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
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> pll;
typedef vector<vector<int> > vvi;
typedef vector<vector<ll> > vll;
const ll inf = 1LL << 60;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	//cout << fixed << setprecision(15);
    int H,W,K;cin>>H>>W>>K;
    int sx,sy,gx,gy;
    cin>>sx>>sy>>gx>>gy;
    sx--; sy--; gx--; gy--;
    vector<vector<int> > G(H,vector<int>(W));
    REP(i,H){
        REP(k,W){
            char a; cin>>a;
            if(a == '.')G[i][k] = INF;
            else G[i][k] = -1;
        }
    }
    G[sx][sy] = 0;

    queue<P> que;
    que.push(P(sx,sy));
    while(que.empty() == false){
        P now = que.front(); que.pop();
        if(now == P(gx,gy))break;
        REP(i,4){
            FOR(j,1,K+1){
                int nx = now.first + j*dx[i];
                int ny = now.second + j*dy[i];
                if(nx < 0 || nx >= H || ny < 0 || ny >= W || (G[nx][ny] == -1))break;
                else{
                    if(/*G[nx][ny] != -1 &&*/ G[now.first][now.second] >= G[nx][ny]) break;
                    else{
                        G[nx][ny] = G[now.first][now.second] + 1;
                        que.push(P(nx,ny));
                    }
                    //else break;
                }
            }
        }
    }

    cout << (G[gx][gy] != INF ? G[gx][gy] : -1) << endl;   


}
