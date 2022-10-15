#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<algorithm>
#include <queue>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;
const ll max_n = 100000;
const ll max_m = 100000;
using namespace std;
typedef pair<ll,ll> P;
const ll maxv = 100000;
const ll money_first = 1e15;

struct edge{
    ll to;
    ll cost;
};

template<class Abel> struct Dijkstra{
    priority_queue<P,vector<P>,greater<P> > que;
    vector<vector<edge> > G;
    vector<Abel> d;
    vector<ll> prev;
    Dijkstra(ll s){
        G.resize(maxv);
        d.resize(maxv,INF);
        prev.resize(maxv);
        d[s] = 0;
        que.push(P(0,s));
    }
    
    void dijkstra(){
        while(!(que.empty())){
            P p = que.top(); que.pop();
            ll v = p.second;
            if(d[v] < p.first)continue;
            for(ll i = 0; i < G[v].size(); i++){
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

bool compare(P a,P b){
    if(a.second == b.second){
        return a.first > b.first;
    }
    return a.second < b.second;
}
ll n,m,s,t;
int main(){
    cin >> n >> m >> s >> t;
    s--; t--;
    Dijkstra<ll> yen(s), snook(t);
    REP(i,m){
        ll u,v,a,b;
        cin >> u >> v >> a >> b;
        u--; v--;
        edge yen_u = {.to = v,.cost = a};
        edge yen_v = {.to = u,.cost = a};
        edge snook_u = {.to = v,.cost = b};
        edge snook_v = {.to = u,.cost = b};
        yen.G[u].push_back(yen_u);
        yen.G[v].push_back(yen_v);
        snook.G[u].push_back(snook_u);
        snook.G[v].push_back(snook_v);
    }

    yen.dijkstra();
    snook.dijkstra();

    vector<P> mincost;
    REP(i,n){
        //cout << yen.d[i] << " " << snook.d[i] << endl;
        P p(i+1, yen.d[i] + snook.d[i]);
        mincost.push_back(p);
    }

    sort(ALL(mincost),compare);
    /*REP(i,n){
        cout << mincost[i].first << " " << mincost[i].second << endl;
    }*/


    ll itr = 0;
    //int min_itr = 0;
    REP(i,n){       
        while(mincost[itr].first <= i){
            itr++;
        }
        
        cout << money_first - mincost[itr].second << endl;
    }

}