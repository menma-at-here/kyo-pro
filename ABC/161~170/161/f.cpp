#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include<numeric>
#include<cmath>
#include<map>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(ll i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> pll;
const ll inf = 1LL << 60;

int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	//cout << fixed << setprecision(15);
    ll N; cin>>N;
    ll sq = (ll)(sqrt(N));
    int ans = 1;

    vector<bool> ifprimes(sq+1,true);
    vector<ll> primes;
    for(int i = 2;i <= sq; i++){
        if(ifprimes[i] == false) continue;
        else{
            primes.push_back(i);
            for(int k = 2*i; k <= sq; k+=i){
                ifprimes[k] = false;
            }
        }
    }
    vector<ll> divide;
    map<ll,int> minus;
    //ll now_n = N;
    FOR(i,2,sq+1){
        if(N % i == 0) {
            divide.push_back(i);
            if(i*i != N){
                divide.push_back(N / i);
            }
        }     
    }

    REP(i,divide.size()){
        ll now_n = N;
        while(now_n % divide[i] == 0){
            now_n /= divide[i];
        }
        if(now_n % divide[i] == 1)ans++;
    }

    ll minus_n = N-1;
    REP(i,primes.size()){
        if(minus_n%primes[i] == 0){
            while(minus_n % primes[i] == 0){
                minus[primes[i]]++;
                minus_n /= primes[i];
            }
        }
    }
    if(minus_n > 1)minus[minus_n]++;
    ll mm = 1;
    for(auto itr = minus.begin(); itr != minus.end(); ++itr){
        mm *= (itr->second+1);
    }
    ans += (mm-1);

    cout << ans << endl;
}