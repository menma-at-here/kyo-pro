#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include<numeric>
#include<cmath>
#include<bitset>
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
int N,M;
vector<vector<int> > G;
vector<ll> dp;

void dfs(int start ,int now, vector<bool> flag){  //これつけるとなぜか実行時えらーでた　なんで？
    flag[now] = true;
    if(now == start) G[now][start] = -INF;
    else{
        G[start][now] = 1; 
        G[now][start] = -1;
    }
    REP(i,N){
        if(G[now][i] == 1 && !flag[i]){
            dfs(start, i,flag);
        }
    }

}

ll dpfunc(ll S){
    if (S == 0 || bitset<64>(S).count() == 1) return dp[S] = 1;

    //if(S == 0);
    if(dp[S] != -1) return dp[S];
    
    dp[S] = 0;
    REP(u,N){
        bool flag = true;
        ll temp = 0;
        if((S & (1<<u) )== 0) continue;
        //if(bitset<64>(S).count() == 1) return dp[S] = 1;
        REP(v,N){
            if((S^(1<<u)) & (1<<v)){
                if(G[u][v] == 1){
                    flag = false; break;
                }
                //else continue;//temp += dpfunc(S^(1<<u));
            }
        }
        if(flag) dp[S] += dpfunc(S^(1<<u));
        //dp[S] += temp;

    }
    return dp[S];
}

int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	//cout << fixed << setprecision(15);
    cin>>N>>M;
    G.resize(N,vector<int>(N,0));
    REP(i,M){
        int x,y; cin>>x>>y;
        x--; y--;
        G[y][x] = -1;
        G[x][y] = 1;
    }

    REP(i,N){  
        vector<bool> flag(N,false);
        dfs(i,i,flag);
    }

    /*REP(i,N){
        REP(k,N){
            cout << G[i][k] << " ";
        }
        cout << endl;
    }*/

    dp.resize((1<<N),-1);
    
    ll ans = dpfunc((1<<N)-1);

    cout << ans << endl;
}