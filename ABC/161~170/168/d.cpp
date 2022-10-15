#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include<numeric>
#include<cmath>
#include <queue>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;



int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	//cout << fixed << setprecision(15);
    int N,M;
    cin>>N>>M;
    vector<int> A(M),B(M);
    vector<vector<int> > G(N);
    vector<int> flag(N,-1);
    flag[0] = 0;
    REP(i,M){
        cin >> A[i] >> B[i];
        A[i]--; B[i]--;
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }
    vector<int> dp(N);
    queue<P> que; que.push(P(0,0)); //first = 場所, second = なんこめか
    while(!que.empty()){
        P now = que.front(); que.pop();

        REP(i,G[now.first].size()){
            int next = G[now.first][i];
            int itr = now.second + 1;
            if(flag[next] == -1){
                flag[next] = now.second + 1;
                que.push(P(next,itr));
                dp[next] = now.first;
            }
        }
    }

    cout << "Yes" << endl;

    FOR(i,1,N){
        cout << dp[i] + 1 << endl;
    }



}