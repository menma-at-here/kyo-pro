#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include<numeric>
#include<cmath>
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
using vvii = vector<vector<int> >;
using vvll =  vector<vector<ll> >;

const ll inf = 1LL << 60;

struct Hop{
    int N,M;
    vvii G;
    vector<vector<int> >  done;
    int S,T;
    queue<P> que;
    Hop(){
        cin>>N>>M;
        G.resize(N);
        done.resize(3,vector<int>(N,-1));
        REP(i,M){
            int u,v; cin>>u>>v;
            u--; v--;
            G[u].push_back(v);
        }
        cin>>S>>T;
        S--; 
        T--;
    }


    int bfs(){
        que.push(P(0,S));
        while(!que.empty()){
            P now = que.front(); que.pop();
            bfs3(now.first, now.second);
        }
        return done[0][T];
    }

    void bfs3(int turn, int s){
        queue<P> que3;
        que3.push(P(0,s));
        while(!que3.empty()){
            P nownow = que3.front(); que3.pop();
            int ken = nownow.first; //何歩めか
            int v = nownow.second; // どの街か
            if(ken == 3){    //まずken = 3の場合を除外しなければいけない　　ここに&& done[0][v]を加えてしまうと、除外しきれず次のelseに入ってしまう
                if(done[0][v] == -1){
                //done[0][v] = turn+1;
                Hop::que.push(P(turn+1, v));
                //return;
                }
            }

            else if(done[ken][v] == -1){
                done[ken][v] = turn;
                REP(k,G[v].size()){
                    int next = G[v][k];
                    que3.push(P(ken+1,next));
                }
            }

        }
    }
};

int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	//cout << fixed << setprecision(15);
    Hop hop;
    int ans = hop.bfs();
    cout << ans << endl;
}