#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

const int Max_H = 500, Max_W = 500;

int H,W;
vector<vector<char> > C(Max_H,vector<char>(Max_W));
typedef pair<int,int> P;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int sx,sy;
int gx,gy;
bool dfs(int,int);

int main(){
    cin >> H >> W;
    REP(i,H){
        REP(k,W){
            char ch;
            cin >> ch;
            C.at(i).at(k) = ch;
            if (ch == 's'){
                sx = i; sy = k;
            }
            else if(ch == 'g'){
                gx = i;gy = k;
            }
        }
    }
    //cout << sx << ' ' << sy << endl; 
    bool ans = dfs(sx,sy);
    /*REP(i,H){
        REP(k,W){
            cout << C[i][k];
        }
        cout << endl;
    }*/
    if(ans){cout << "Yes" << endl;}
    else{cout << "No" << endl;}

    return 0;
}

bool dfs(int x,int y){
    //x = sx,y = sy;
    C[x][y] = '#';
    REP(i,4){
        int nx = x + dx[i], ny = y + dy[i];
        if(0 <= nx && nx < H && 0 <= ny && ny < W){
            if(C[nx][ny] == 'g'){return true;}
            else if(C[nx][ny] == '.'){
                C[nx][ny] = '#';
                if(dfs(nx,ny)) return true;
            }
        }
    }
    return false;

}