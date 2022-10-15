#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include<numeric>
#include<cmath>
#include<map>
#include<iomanip>
#include<queue>
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
vector<vector<int> > G;

void bfs(vector<int>& maze, int start){ 
    maze[start] = 0;
    queue<int> que;
    que.push(start);
    while(!que.empty()){
        int now = que.front();
        que.pop();
        REP(i,G[now].size()){
            int next = G[now][i];
            if(maze[next] == -1){
                maze[next] = maze[now] + 1;
                que.push(next);
            }
        }
    }
}

int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(15);

    int N,u,v; cin >>N>>u>>v;  //uが逃げる人,vが鬼
    u--; v--;
    G.resize(N);
    REP(i,N-1){
        int a,b;
        cin >>a>>b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<int> bfsnige(N,-1),bfsoni(N,-1);

    bfs(bfsnige, u);
    bfs(bfsoni, v);

    vector<P> far;
    REP(i,N){
        if(bfsnige[i] < bfsoni[i]){
            far.push_back(P(bfsoni[i], i));
        }
    }

    sort(ALL(far),greater<P>());
    int farest = far[0].second;
    //cout << farest << endl;
    
    int ans;
    if((bfsoni[farest] - bfsnige[farest]) % 2){
        ans = bfsoni[farest] - 1;
    }
    else{ans = bfsoni[farest] - 1;}

    cout << ans << endl;
}

