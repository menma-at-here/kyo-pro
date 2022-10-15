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
using vvi = vector<vector<int> >;
using vvll =  vector<vector<ll> >;

const ll inf = 1LL << 60;

int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	//cout << fixed << setprecision(15);
    ll k,q; cin >> k >> q;
    vector<ll> d(k);
    REP(i,k){
        cin >> d[i];
    }

    vector<ll> ans(q);
    REP(i,q){
        ll n,x,m; cin >> n >> x >> m;
        x %= m;
        vector<ll> dmod(k), ruiseki(k+1,0),zeros(k+1,0);
        //ll ruiseki = 0;
        //ll zeros = 0;
        REP(j,k){
            dmod[j] = d[j] % m;
            //cout << dmod[j] << " ";
            ruiseki[j+1] =ruiseki[j] + dmod[j];
            if(ruiseki[j+1] == ruiseki[j]){
                zeros[j+1] = zeros[j] + 1;   // a1 = a0 + d0 で、d0 = 0 の場合
            }
            else zeros[j+1] = zeros[j];
        }
        //cout << endl;
        ll shou = (n-1) / k;
        ll amari = (n-1) % k;
        ll sum = 0;
        ll zero = 0;
        sum = x + shou * ruiseki[k] + ruiseki[amari];
        zero = zeros[k] * shou + zeros[amari];
        ans[i] = (n - 1) - sum / m - zero;
        
    }
    REP(i,q){
        cout << ans[i] << endl;
    }
}