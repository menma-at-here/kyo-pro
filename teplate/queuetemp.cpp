#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <iomanip>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 100000
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;


typedef pair<int,int> P;
vector<string> field;
//vector<vector<int> > d;
int N,M;
int sx,sy;
int gx,gy;
int bfs(vector<vector<int> >&);
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){

}

int bfs(vector<vector<int> > &d){
    queue<P> que;
    REP(i,N){
        REP(j,M){
            d[i][j] = INF;
        }       
    }
    que.push(P(sx,sy));
    d[sx][sy] = 0;
}