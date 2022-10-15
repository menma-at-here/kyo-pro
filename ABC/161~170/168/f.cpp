#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include<numeric>
#include<cmath>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 1e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	//cout << fixed << setprecision(15);
	int N,L; cin>>N>>L;
	vector<bool> X(L+1,false);
	REP(i,N){
		int x; cin>>x;
		X[x] = true;
	}
	int t1,t2,t3;
	cin>>t1>>t2>>t3;

	vector<vector<int> > dp(5,vector<int>(L+1,INF));
	dp[0][0] = 0;
	REP(i,L){
		int mini = min(dp[0][i] + t1, dp[1][i] + (t1+t2)/2);
		mini = min(mini, dp[4][i]+(t1+t2)/2);
		dp[0][i+1] = mini;
		if(X[i+1]) dp[0][i+1] += t3;

		dp[1][i+1] = dp[0][i] + (t1+t2)/2;
		dp[2][i+1] = dp[0][i] + (t1+t2)/2;
		dp[3][i+1] = dp[2][i] + t2;
		dp[4][i+1] = dp[3][i] + t2;
	}

	int ans = INF;
	REP(i,5){
		ans = min(dp[i][L],ans);
	}
	cout<<ans<<endl;
}
