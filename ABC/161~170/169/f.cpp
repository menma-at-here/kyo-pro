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
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> pll;
const ll inf = 1LL << 60;
const ll mod = 998244353;

int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	//cout << fixed << setprecision(15);
    int N,S; cin>>N>>S;
    vector<ll> A(N);
    REP(i,N){
        cin>>A[i];
    }
    vector<vector<ll > > dp(N+1,vector<ll>(S+1,0)); //個数、何通りあるか
    dp[0][0] = 1;
    REP(i,N){
        REP(j,S+1){
            if(A[i] > j){
                dp[i+1][j] = 2 * dp[i][j] %mod;
            }
            else{
                dp[i+1][j] = (2 * dp[i][j] + dp[i][j-A[i]]) % mod;
            }
        }
    }

    cout << dp[N][S] <<endl;


}