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

int W;
int N,K;
typedef pair<int,int> P;

int main(){
    cin >> W;
    cin >> N >> K;
    int width[N], importance[N];
    REP(i,N){
        int a,b;
        cin >> a >> b;
        width[i] = a;
        importance[i]= b;
        }
    vector<vector<P> > dp(N+1, vector<P>(W+1));

    REP(i,N+1){
        REP(j,W+1){
            if(i == 0 || j == 0){dp[i][j] = P(0,0);}
            else if(j < width[i-1] || dp[i-1][j - width[i-1]].second >= K){
                dp[i][j] = dp[i-1][j];
            }
            else{
                if(dp[i-1][j].first >= dp[i-1][j-width[i-1]].first + importance[i-1]){dp[i][j] = dp[i-1][j];}
                else{
                    dp[i][j].first = dp[i-1][j-width[i-1]].first + importance[i-1];
                    dp[i][j].second = dp[i-1][j-width[i-1]].second + 1;
                }
            }
        }
    }
    cout << dp[N][W].first << endl;
}