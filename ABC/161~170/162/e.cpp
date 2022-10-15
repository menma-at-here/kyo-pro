#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include<numeric>
#include<cmath>
#include<map>
#include<iomanip>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
using pll = pair<ll,ll>;
using pdd = pair<double,double>;
using vvi = vector<vector<int> >;
using vvll =  vector<vector<ll> >;
const ll mod = 1e9 + 7;

ll mpow(ll x, ll n){
    ll ans = 1;
    while(n){
        if(n % 2){
            ans = ans * x % mod;
        }
        x = x * x % mod;
        n >>= 1;
    }
    return ans;
}

int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(15);
    ll N,K; cin >>N>>K;
    vector<ll> kosuu(K+1);
    ll ans = 0;
    for(ll i = K; i>= 1; i--){
        ll floor = K / i;
        kosuu[i] = mpow(floor, N);
        for(ll j = 2;j * i <= K ; j++){
            kosuu[i] += (mod - kosuu[j * i]) % mod;
            kosuu[i] %= mod;
        }
        ans += i * kosuu[i];
        ans %= mod;

    }
    //cout << kosuu[100] << endl;
    cout << ans << endl;

}

