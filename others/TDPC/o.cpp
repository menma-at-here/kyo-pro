#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

ll Comb(ll n,ll m){
    int ans = 1;
   REP(i,m){
       ans *= (n-i);
       ans %= mod;
   }
   REP(k,m){
       ans /= (k+1);
   }
   return ans % mod;
}

int main(){
    vector<int> alpha;
    REP(i,26){
        int a;
        cin >> a;
        if(a != 0){
            alpha.push_back(a);
        }
    }
    sort(ALL(alpha),greater<int>());
    int sum_alpha = accumulate(ALL(alpha),0);
    int nummoji = alpha.size();
    int dp[nummoji][sum_alpha];
}

/*int main(){
    vector<int> alpha
    REP(i,26){
        int a;
        cin >> a;
        if(a != 0){
            alpha.push_back(a);
        }
    }
    sort(ALL(alpha));
    REP(i,alpha.size()){
        cout << alpha[i] << endl;
    }

    int moji = 0;
    vector<ll> dp(alpha.size()+1,1);
    REP(i,dp.size()-1){
        dp[i+1] = dp[i] * Comb(moji,alpha[i]);
        dp[i+1] %= mod;
        moji += alpha[i];
    }
    REP(i,dp.size()){
        cout << dp[i] << endl;
    }
    cout << dp[dp.size()-1] << endl;
    
}*/