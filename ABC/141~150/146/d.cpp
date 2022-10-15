#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include<numeric>
#include<cmath>
#include<queue>
#include<set>
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
 
struct Edge{
    int number;
    int to;
    int color;
    Edge(int n,int t,int c){
        number = n;
        to = t;
        color = c;
    }
};
 
int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	//cout << fixed << setprecision(15);
    int N; cin>>N;
    vector<vector<Edge> > G(N);
    vector<int> ans(N-1,0);
    vector<bool> done(N,false);
    int maxi = 0;
    REP(i,N-1){
        int a,b;cin>>a>>b;
        a--;b--;
        G[a].push_back(Edge(i,b,0));
        G[b].push_back(Edge(i,a,0));
        int now = max(G[a].size(),G[b].size());
        maxi = max(now,maxi);
    }

    queue<int> que;
    que.push(0);
    while(!que.empty()){
        int now = que.front(); que.pop();
        done[now] = true;
        //if(!done[now]){
        int now_color = 1;
        set<int> have;
        REP(i,G[now].size()){
            Edge next = G[now][i];
            have.insert(ans[next.number]);     
        }
        REP(i,G[now].size()){
            Edge next = G[now][i];
            if(ans[next.number] != 0)continue;
            while(have.find(now_color) != have.end()){
                now_color++;
            }
            ans[next.number] = now_color;
            have.insert(now_color);
            if(done[next.to] == false){
                que.push(next.to);
            }
        }
        //}
    }
    cout << maxi<<endl;
    REP(i,ans.size()){
        cout << ans[i]<<endl;
    }

}