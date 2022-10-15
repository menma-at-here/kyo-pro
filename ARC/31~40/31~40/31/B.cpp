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

const int N = 10;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
vector<vector<char> > island(N,vector<char>(N));
void shima(int x, int y,char[N][N]);

int main(){
    REP(i,N){
        REP(k,N){
            char c;
            cin >> c;
            island.at(i).at(k) = c;
        }
    }


    bool ans = 0;
    int count = 0;
    REP(i,N){
        REP(k,N){
            char ocean[N][N];
    
            REP(l,N){
                REP(m,N){
                    ocean[l][m] = island.at(l).at(m);
                }
            }
            int count = 0;
            if(ocean[i][k] == 'x'){
               ocean[i][k] = 'o';
               shima(i,k,ocean);
               REP(l,N){
                    REP(m,N){
                        if(ocean[l][m] == 'x'){count++;}                      
                    }
               }
               if(count == N * N){ans = true;break;}
               //cout << count << endl;
               ocean[i][k] = 'x';
            }
        }   
        if(ans) break;
    }
    cout << (ans ? "YES" : "NO") << endl;
}

void shima(int x,int y,char ocean[N][N]){
    //int count = 0;
       
    if (ocean[x][y] == 'x'){return ;}
    else{
        ocean[x][y] = 'x';
        REP(i,4){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 <= nx && nx < N && 0 <= ny && ny < N){
                shima(nx,ny,ocean);
            }
        }
    }

}