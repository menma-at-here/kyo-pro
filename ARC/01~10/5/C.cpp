#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
//#include <iomanip>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF -2
#define INF2 10000000
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;


typedef struct{
    int x;
    int y;
}Tuple;
vector<string> field;
vector<vector<int> > d;
int N,M;
int sx,sy;
int gx,gy;
bool bfs(vector<vector<int> >&);
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    REP(i,N){
        string *s1;        
        cin >> *s1;
        field.push_back(s1);
    }
    REP(i,N){
        REP(k,M){
            if (field.at(i).at(k) == 's'){sx = i, sy = k;}
            if (field.at(i).at(k) == 'g'){gx = i, gy = k;}
        }
    }
   vector <vector<int> > d(N,vector<int>(M)); 

    /*cout <<"(sx,sy):" << sx << " " << sy << endl;
    cout <<"(gx,gy):" << gx << " " << gy << endl;*/
    /*REP(i,N){
        REP(k,M){
            if(d[i][k] == INF){cout << '#';}
            else{cout << d[i][k];}
        }
        cout << endl;
    }*/
    bool ans = bfs(d);
    /*REP(i,N){
        REP(k,M){
            if(d[i][k] == INF){cout << " #";}
            else{cout <<setw(2)<< d[i][k];}
        }
        cout << endl;
    }*/
    cout << (ans ? "YES" : "NO") << endl;
    
    return 0;
}

bool bfs(vector<vector<int> > &d){
    bool flag = false;
    queue<Tuple> que;
    REP(i,N){
        REP(j,M){
            d[i][j] = INF;
        }       
    }
    Tuple start = {sx,sy};
    que.push(start);
    d[sx][sy] = 0;

    while(que.size()){
        Tuple t = que.front();
        que.pop();
    
        if(t.x == gx && t.y == gy && d[gx][gy] != INF){flag = true; break;}
        else{
            REP(i,4){
                int nx = t.x + dx[i], ny = t.y + dy[i];
                if(0 <= nx && nx < N && 0 <=ny && ny < M && field[nx][ny] != '#' && d[t.x][t.y] <= 2){
                    Tuple nt = {nx,ny};
                    que.push(nt);
                    if(d[nx][ny] == INF) {d[nx][ny] = d[t.x][t.y];}
                    else if(d[nx][ny] > d[t.x][t.y]){d[nx][ny] = d[t.x][t.y];}
                    else{continue;}
                }
                else if (0 <= nx && nx < N && 0 <=ny && ny < M && field[nx][ny] == '#' && d[t.x][t.y] <= 1){
                    Tuple nt = {nx,ny};
                    que.push(nt);
                    if(d[nx][ny] == INF) {d[nx][ny] = d[t.x][t.y] + 1;}
                    else if(d[nx][ny] > d[t.x][t.y] + 1){d[nx][ny] = d[t.x][t.y] + 1;}
                    else{continue;}
                }
            }
        }
    }
    return flag;

}