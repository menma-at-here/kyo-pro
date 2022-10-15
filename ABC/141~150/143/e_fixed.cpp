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
typedef pair<int,ll> pil;
typedef pair<P,int> ppi;
const int maxv = 500;

struct edge{
    int to;
    int cost;
    edge(){

    }
    edge(int a,int b){
        to = a, cost = b;
    }
};

vector<vector<int> > G;
int N,M,L;

struct Dijkstra{
    priority_queue<ppi,vector<ppi>,greater<ppi> > que;
    //static vector<vector<edge> > G;
    vector<P> d; // .first = 最小回数　.secnod = タンクの容量
    //int L;
    //vector<int> prev;
    vector<bool> used;
    Dijkstra(){

    }
    Dijkstra(int s){
        //G.resize(maxv);
        d.resize(maxv,P(INF,0));
        //prev.resize(maxv);
        d[s] = P(0,L);
        que.push(ppi(P(0,L), s)); //.first = startからの距離　second = 現在地点
    }

    void init(int s){
        d.resize(maxv,P(INF,0));
        d[s] = P(0,L);
        que.push(ppi(P(0,L), s)); //.first = startからの距離　second = 現在地点
        used.resize(maxv,false);
    }
    
    void dijkstra(){
    /*while(!(que.empty())){
            ppi p = que.top(); que.pop();
            int v = p.second;
            if(d[v].first < p.first.first || (d[v].first == p.first.first && d[v].second > p.first.second) ) continue;
            for(int i = 0; i < G[v].size(); i++){
                edge e = G[v][i];
                bool flag = false;
                if(L < e.cost) continue;

                if(d[v].second < e.cost){
                    if(d[e.to].first > d[v].first + 1)flag = true;
                    else if(d[e.to].first == d[v].first+1 && d[e.to].second < L - e.cost)flag = true;
                    if(flag){
                        d[e.to] = P(d[v].first + 1, L-e.cost);
                        que.push(ppi(d[e.to], e.to));
                    }
                }
                else{
                    if(d[e.to].first > d[v].first)flag = true;
                    else if(d[e.to].first == d[v].first && d[e.to].second < d[v].second - e.cost)flag = true;
                    if(flag){
                        d[e.to] = P(d[v].first, d[v].second - e.cost);
                        que.push(ppi(d[e.to], e.to));
                    }
                }
                
            }

        }
    }*/
    while(true){
        int v = -1;
        for(int u = 0; u < N; u++){
            if(!used[u]){
                bool flag = false;
                if(v == -1) flag = true;
                else if(d[v].first > d[u].first || (d[u].first == d[v].first && d[v].second < d[u].second)) flag = true;
                /*if(d[v].second < G[v][u]){
                    if(v == -1)flag = true;
                    else if(d[u].first > d[v].first + 1) flag = true;
                    else if (d[u].first == d[v].first + 1 && d[u].second < d[v].second) flag = true;
                }
                else{
                    if(v == -1)flag = true;
                    else if(d[u].first > d[v].first) flag = true;
                    else if (d[u].first == d[v].first && d[u].second < d[v].second - G[v][u]) flag = true;
                }*/
                if(flag){
                    v = u;
                }
            }
        }
        if(v == -1) break;
        used[v] = true;

        for(int u =0 ; u < N; u++){
            bool flag = false;
            if(L < G[v][u])continue;
            if(d[v].second < G[v][u]){
                    if(d[u].first > d[v].first + 1) flag = true;
                    else if (d[u].first == d[v].first + 1 && d[u].second < L - G[v][u]) flag = true;
                    if(flag) d[u] = P(d[v].first+1, L - G[v][u]);
                }
                else{
                    if(d[u].first > d[v].first) flag = true;
                    else if (d[u].first == d[v].first && d[u].second < d[v].second - G[v][u]) flag = true;
                    if(flag) d[u] = P(d[v].first, d[v].second - G[v][u]);
                }
        }
    }
    }
};

int main(){
    //int N,M,L;
    cin>>N>>M>>L;
    G.resize(N,vector<int>(N,INF));
    REP(i,M){
        int a,b,c;
        cin>>a>>b>>c;
        a--; b--;
        G[a][b] = c;
        G[b][a] = c;
    }
    /*cout<<endl;
    REP(i,N){
        cout << i<<":";
        REP(k,G[i].size()){
            cout << G[i][k].to <<" " <<  G[i][k].cost<<" ";
        }
        cout << endl;
    }*/
    int Q; cin>>Q;
    vector<P> st(Q);

    Dijkstra car[N];
    REP(i,N){
       car[i].init(i);
        car[i].dijkstra();
    }

    vector<int> ans(Q);
    REP(i,Q){
        int s,t;cin>>s>>t;
        s--;t--;
        //st[i] = P(s,t);
        ans[i] = (car[s].d[t].first != INF ? car[s].d[t].first : -1);
        //ans[i] = car[s].d[t].first;
    }
    //sort(ALL(st));

    REP(i,Q){
        cout << ans[i] << endl;
    }
}