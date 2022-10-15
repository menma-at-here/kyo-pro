#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
const int max_n = 200000;

int main(){
    string S;
    cin>>S;
    ll n = S.length();
    vector<ll> mod(max_n,0);
    //int modi = 1;
    mod[0] = 1;
    REP(i,max_n){
        mod[i+1] = 10*mod[i] % 2019;
    }
    vector<ll> amari(2019,0);
    vector<ll> dp(max_n+1,0);
    ll amari0 = (S.at(0) - '0');
    dp[0] = 0;
    amari[0]++;
    REP(i,n){
       dp[i+1] = ((dp[i] + (S.at(S.length() - 1 - i) - '0') * mod[i] ) % 2019);
       amari[dp[i+1]]++;
       //cout << dp[i+1] << endl;
    }

    ll ans = 0;
    REP(i,2019){
        ans += amari[i] * (amari[i]-1) / 2;
    }
    cout << ans <<endl;

}