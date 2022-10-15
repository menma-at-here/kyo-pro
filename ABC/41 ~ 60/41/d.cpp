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
vector<vector<ll> > dp;

void dfs(int start ,int now, vector<bool> flag){
    flag[now] = true;
    if(now == start) G[now][start] = -INF;
    else{
        G[start][now] = 1; 
        G[now][start] = -1;
    }
    REP(i,M){
        if(G[now][i] == 1 && !flag[i]){
            dfs(start, i,flag);
        }
    }

}

ll dpfunc(ll S, ll v){
    //cout << S << " " << v << " " <<  dp[S][v] << endl;
    //cout << S << " " << v << endl;
    if(bitset<64>(S).count() == 1){
        if(S & (1<<v)) return dp[S][v] = 1;
        else return dp[S][v] = 0;
    }

    if((S & (1<<v)) == 0) return dp[S][v] = 0;
    if(dp[S][v] != -1) return dp[S][v];

    dp[S][v] = 0;
    REP(u,N){
        //if(G[u][v] >= 0){
        ll temp = dpfunc(S^(1<<v), u);
        if(S == 14){
            cout << (S^(1<<v)) << " " << u << " " << temp <<  endl;
        }
        if(G[u][v] >= 0) {       //これだと、最後にゴールした人とvしか比べられない。もしuより前にゴールした人がvより遅くなければいけないひとだとすると、ダメ。
            dp[S][v] += temp;
            //cout << S << " " << v << " " <<  dp[S][v] << endl;  
        }     
    }
    //cout << S << " " << v << " " <<  dp[S][v] << endl;
    return dp[S][v];

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

    REP(i,N){
        REP(k,N){
            cout << G[i][k] << " ";
        }
        cout << endl;
    }

    dp.resize((1<<N), vector<ll>(N,-1));
    
    ll ans = 0;
    REP(i,N){
        ans += dpfunc((1<<N)-1, i);
        //cout << i << " " << dpfunc((1<<N)-1, i) << endl;
    }

    cout << ans << endl;
}