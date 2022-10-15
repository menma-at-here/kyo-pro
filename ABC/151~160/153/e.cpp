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
using pdi = pair<double,int>;
using vvi = vector<vector<int> >;
using vvll =  vector<vector<ll> >;


const ll inf = 1LL << 60;

int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	//cout << fixed << setprecision(15);
    int H,N; cin >>H>>N;
    vector<P> vec(N);
    int maxa = 0;
    REP(i,N){
        int a,b; cin >> a >> b;
        maxa = max(maxa,a);
        vec[i] = P(a,b);
    }
    vvi dp(N + 1, vector<int>(H + maxa + 1, INF));
    dp[0][0] = 0;
    REP(i,N){
        REP(j,H+maxa){
            if(j >= vec[i].first){
                dp[i+1][j] = min(dp[i][j],dp[i + 1][j - vec[i].first] + vec[i].second);
            }
            else{
                dp[i+1][j] = dp[i][j];
            }
        }
    }

    int ans = INF;
    for(int i = H; i < H + maxa; i++){
        ans = min(ans, dp[N][i]);
    }

    cout << ans << endl;

    

}