#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <functional>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
//#define INF 1LL << 60
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;
const ll mod = 1e9 + 7;

ll Comb(ll n,ll m){
    ll ans = 1;
    if(n == 0){
        return 1;
    }
    if(m!=0 && m != n){
        REP(i,m){
            ans *= (n-i);
            //ans %= mod;
        }
        REP(k,m){
            ans /= (k+1);
        }
        return ans % mod;
    }
    else{
        return 1;
    }
   
}

int main(){
    vector<ll> alpha;
    REP(i,26){
        ll a;
        cin >> a;
        if(a != 0){
            alpha.push_back(a);
        }
    }
    sort(ALL(alpha),greater<ll>());
    ll sum_alpha = accumulate(ALL(alpha),0); //文字数の合計
    ll nummoji = alpha.size(); //文字の種類
    ll dp[nummoji+1][sum_alpha+1]; //dp[i][j]は、i種類目までの文字を使い、j箇所同じ文字が隣接している時の合計
    REP(i,nummoji+1){
        REP(k,sum_alpha+1){
            dp[i][k] = 0;
        }
    }

    dp[0][0] = 1;
    dp[1][alpha[0]-1] = 1;
    ll len[nummoji+1];
    len[0] = 0;
    len[1] = alpha[0];
    if(nummoji > 1){
    for(ll i = 1; i <nummoji; i++){
        len[i+1] = len[i] + alpha[i];
        REP(j,sum_alpha-1){
            for(ll k = 1; k <= alpha[i]; k++){
                for(ll l = 0; l <= min<ll>(j,k) ; l++){
                    if(k-l <= len[i+1] +1 - j){
                        dp[i+1][j+alpha[i] - k - l] += dp[i][j] * (Comb(alpha[i]-1, k-1) % mod) * (Comb(j,l)%mod) * (Comb(len[i]+1-j,k-l)%mod);
                        dp[i+1][j+alpha[i] - k - l] %= mod;
                        /*if(dp[i][j] != 0){
                            cout << Comb(alpha[i]-1, k-1) << Comb(len[i+1]+1-j,k-l) << endl;
                             cout << "ijkl" << i << " "<<j<<" "<<k<<" "<<l<< endl;
                        }*/
                       // cout << "ijkl" << i << " "<<j<<" "<<k<<" "<<l<< endl;
                    }
                }
            }
        }
    }
    }
    /*REP(i,nummoji+1){
        cout<<dp[i][0] << " " <<dp[i][1] << endl;
    }*/
    cout << dp[nummoji][0] << endl;
}