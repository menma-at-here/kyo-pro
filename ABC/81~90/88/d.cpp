#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 1000000
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int H,W;
vector<string> S;
typedef pair<int,int> P;
vector<vector<int> > field;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int gx, gy;
bool bfs();

int main(){
    cin >> H >> W;
    S.resize(H);
    field.resize(H,vector<int>(W));
    REP(i,H){
        string s; 
        cin >> s;
        S[i] = s;
    }
    int count = 0; // #を数える
    REP(i,H){
        REP(j,W){
            if(S[i][j] == '#'){count++;}
            field[i][j] = INF;
        }
    }
    bool flag = bfs();

    int ans = H * W - count - field[H-1][W-1] - 1;

    cout << (flag ? ans : -1) << endl;
}

bool bfs(){
    bool flag = false;
    queue<P> que;
    int sx = 0,sy = 0;
    que.push(P(sx,sy));
    field[sx][sy] = 0;

    while(!que.empty()){
        P p = que.front();
        if(p.first == H - 1 && p.second == W -1){flag = true; break;}
        else{
        que.pop();
            REP(i,4){
                int nx = p.first + dx[i], ny = p.second + dy[i];
                if(0 <= nx && nx < H && 0 <= ny && ny < W && S[nx][ny] == '.' && field[nx][ny] == INF){
                    que.push(P(nx,ny));
                    field[nx][ny] = field[p.first][p.second] + 1;
                }
            }
        }
    }
   return flag;
}



