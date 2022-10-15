#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<algorithm>
#include <queue>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
const int max_n = 100000;
const int max_m = 100000;
using namespace std;
typedef pair<int,int> P;
const int maxv = 100000;
int V;

struct edge{
    int to;
    int cost;
    edge(int a,int b){
        to = a, cost = b;
    }
};

template<class Abel> struct Dijkstra{
    priority_queue<P,vector<P>,greater<P> > que;
    vector<vector<edge> > G;
    vector<Abel> d;
    vector<int> prev;
    Dijkstra(int s){
        G.resize(maxv);
        d.resize(maxv,INF);
        prev.resize(maxv);
        d[s] = 0;
        que.push(P(0,s)); //.first = startからの距離　second = 現在地点
    }
    
    void dijkstra(){
    while(!(que.empty())){
            P p = que.top(); que.pop();
            int v = p.second;
            if(d[v] < p.first)continue;
            for(int i = 0; i < G[v].size(); i++){
                edge e = G[v][i];
                if(d[e.to] > d[v] + e.cost){
                    d[e.to] = d[v] + e.cost;
                    prev[e.to] = v;
                    que.push(P(d[e.to], e.to));
                }
            }

        }
    }


};

template <class Abel> struct Dijkstra{
    vector<vector<int> > G;
    vector<Abel> d;
    vector<bool> used;
    Dijkstra(int s){
        G.resize(maxv,vector<int>(maxv,INF));
        d.resize(maxv,INF);
        d[s] = 0;
        used.resize(maxv,false);
    }

    while(true){
        v = -1;
        for(int u = 0; u < V; u++){
            if(!(used[u]) && (v == -1 || d[v] > d[u]))v = u;
        }
        if(v == -1)break;
        used[v] = true;

        REP(u,V){
            d[u] = min(d[u], d[v] + G[v][u]);
        }
    }
};