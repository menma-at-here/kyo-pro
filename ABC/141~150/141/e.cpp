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
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<vector<int> > vvi;
typedef vector<vector<ll> > vll;
typedef pair<ll,ll> pll;
const ll inf = 1LL << 60;

int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	//cout << fixed << setprecision(15);
    int N;cin>>N;
    string S; cin>>S;
    vvi dp(N,vector<int>(N+1,-1));
    int maxi = 0;
    REP(i,N-1){
        FOR(k,i+1,N){
            if(dp[i][k] != -1) continue;
            int nowi = i;
            int nowk = k;
            int itr = 0;
            while(S[nowi] == S[nowk]){
                nowi++; nowk++;
                itr++;

                if(nowk >= N || nowi >= k) break;
            }
            dp[i][k] = itr;
            maxi = max(maxi,itr);
            for(int j = 1; j < itr; j++){
                dp[i+j][k+j] = 0;
            }
        }
    }

    cout<<maxi<<endl;
}