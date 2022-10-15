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

const int maxn = 10010;
int N;
int ans = 0;
vector<int> p;
int main(){
    cin >> N;
    REP(i,N){
        int c;
        cin >> c;
        p.push_back(c);
    }
    int sum_p = accumulate(ALL(p), 0);
    int dp[sum_p + 1];
    REP(i,sum_p) dp[i] = 0;
    dp[0] = 1;
    REP(i,N){
        REPR(k,sum_p){
            if(dp[k] == 1){dp[k + p[i]] = 1;}
        }
    }
    REP(i,sum_p+1){
        if(dp[i] == 1){ans++;}
        //cout << dp[i] << " ";
    }
    //cout << endl;
    cout << ans << endl;
    
}