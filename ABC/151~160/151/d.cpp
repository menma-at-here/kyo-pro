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
using vvi = vector<vector<int> >;
using vvll =  vector<vector<ll> >;
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
 
const ll inf = 1LL << 60;

struct Maze{
    int H,W;
    vector<string> S;

    Maze(){
        cin >> H >> W;
        S.resize(H);
        REP(i,H){
            cin >> S[i];
        }
    }

    int cal_max(P s,vector<string> maze){
        vector<vector<int> > seen(H,vector<int>(W,-1));
        queue<P> que;
        if(maze[s.first][s.second] == '#'){
            return -1;
        }
        que.push(s);
        seen[s.first][s.second] = 0;
        int res = 0;
        while(!que.empty()){
            P now = que.front();
            //seen[now.first][now.second] = true;
            que.pop();
            REP(i,4){
                int nx = now.first + dx[i];
                int ny = now.second + dy[i];
                if(0 <= nx && nx < H && 0<=ny && ny < W && maze[nx][ny] == '.' && seen[nx][ny] == -1){
                    seen[nx][ny] = seen[now.first][now.second] + 1;
                    res = max(res,seen[nx][ny]);
                    que.push(P(nx,ny));
                }
            }
        }
        return res;
    }

    int solve(){
        int ans = 0;
        REP(i,H){
            REP(k,W){
                int now = cal_max(P(i,k), S);
                ans = max(ans,now);
            }
        }
        return ans;
    }

};

int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	//cout << fixed << setprecision(15);
    Maze maze;
    cout << maze.solve() << endl;

}