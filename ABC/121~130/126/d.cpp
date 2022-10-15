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
const int maxn = 100000;
const int maxw = 1000000000;

int N;
int u[maxn],v[maxn],w[maxn];
typedef struct edge{
    int to;
    int cost;
}Edge;
vector<vector<edge> > G(maxn);
vector<int> color(maxn,INF);

void dfs(int v, int c){
    color[v] = c;
    if(G[v].size() != 0){
        REP(i,G[v].size()){
            if(color[G[v][i].to] == INF){
                if(G[v][i].cost == 0){color[G[v][i].to] = color[v];}
                else{color[G[v][i].to] = (color[v] + 1) % 2 ;}
                dfs(G[v][i].to, color[G[v][i].to]);
            }
        }
    }
}

int main(){
    cin >> N;
    REP(i,N-1){
        cin >> u[i] >> v[i] >> w[i];
        u[i]--, v[i]--;
        w[i] = w[i] % 2;
        Edge ev = {v[i], w[i]};
        Edge eu = {u[i],w[i]};
        G[u[i]].push_back(ev);
        G[v[i]].push_back(eu);
    }

    REP(i,N){
        if(color[i] == INF){
            dfs(i,0);
        }
        printf("%d\n", color[i]);
    }
}