#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
const int maxn = 100000;
const int maxw = 1000000000;

int N,M;
int a[maxn],b[maxn];


vector<vector<int> > G(maxn);
class Edge{
public:
    int depth;
    int num;
    Edge(int i, int number){
        depth = i;
        num = number;
    }
};
bool operator> (Edge a, Edge b){
    if(a.depth == b.depth) return a.num > b.num;
    return a.depth > b.depth;
}

int main(){
    cin >> N >> M;
    REP(i,M){
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
        G[a[i]].push_back(b[i]);
        G[b[i]].push_back(a[i]);
    }
    int ans = 0;
    REP(i,N){
        priority_queue<Edge,vector<Edge> , greater<Edge> > que;
        REP(k,G[i].size()){
            que.push(Edge(1,G[i][k]));
        }
        while(!que.empty()){
            Edge next = que.top();
            que.pop();
            if(next.depth == 3){
                if(!binary_search(ALL(G[i]), next.num) && next.num != i){
                    G[i].push_back(next.num);
                    G[next.num].push_back(i);
                    que.push(Edge(1,next.num));
                    ans++;
                }
            }

            else{
                REP(k,G[next.num].size()){
                que.push(Edge(next.depth+1,G[next.num][k]) );
                }
            }
            
        }
    }
    cout << ans << endl;
}
//全然ちげえよバーーーーカ