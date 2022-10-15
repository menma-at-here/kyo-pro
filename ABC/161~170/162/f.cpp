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
const ll inf = (1LL<<58);

int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(15);
    int N; cin >> N;
    vector<ll> A(N);
    REP(i,N){
        cin >> A[i];
    }
    if(N % 2){
        vector<vector<ll> > tameshi(1,vector<ll>(N,0));
        vector<vector<vector<ll> > > dp(3,vector<vector<ll> >(2, vector<ll>(N+1,-inf)));  //3: 余裕がどれくらいあるか  2: 選んだか選ばなかったか  N+1: N個目
        dp[0][1][0] = 0;
        REP(i,N){
            REP(j,3){
                if(j == 0){
                    dp[j][0][i+1] = dp[j][1][i] + A[i];
                    dp[j][1][i+1] = dp[j][0][i];
                }
                else{
                    dp[j][0][i+1] = dp[j][1][i] + A[i];
                    dp[j][1][i+1] = max(dp[j][0][i], dp[j-1][1][i]);
                }
            }
        }

        ll ans = max({dp[0][0][N-2], dp[1][0][N-1], dp[2][0][N]});
        cout << ans << endl;
        return 0;
    }
    else{
        vector<vector<vector<ll> > > dp(2,vector<vector<ll> >(2, vector<ll>(N+1,-inf)));

        dp[0][1][0] = 0;
        REP(i,N){
            REP(j,2){
                if(j == 0){
                    dp[j][0][i+1] = dp[j][1][i] + A[i];
                    dp[j][1][i+1] = dp[j][0][i];
                }
                else{
                    dp[j][0][i+1] = dp[j][1][i] + A[i];
                    dp[j][1][i+1] = max(dp[j][0][i], dp[j-1][1][i]);
                }
            }
        }

        ll ans = max(dp[0][0][N-1], dp[1][0][N]);
        cout << ans << endl;
        return 0;
    }
        
}

