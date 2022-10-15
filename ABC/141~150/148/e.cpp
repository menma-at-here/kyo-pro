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
const ll mod = 5e18;

int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(15);
    ll N; cin >> N;
    ll ans = 0;
    if(N % 2){
        cout << ans << endl;
        return 0;
    } 
    ll jyuubai = 10;
    ll now = N;
    if(N == 1e18){
        while(jyuubai <= N){
            ans += N / jyuubai;
            if(jyuubai == 1e18) break;
            jyuubai *= 5;
        }
    }
    else{
        while(jyuubai <= N){
            ans += N / jyuubai;
            jyuubai *= 5;
        }
    }
    
    cout << ans << endl;
    return 0;
}

