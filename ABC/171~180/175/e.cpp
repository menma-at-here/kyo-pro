#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include<numeric>
#include<cmath>
#include<map>
#include<iomanip>
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
const int maxR = 3005;

const ll inf = 1LL << 60;

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	//cout << fixed << setprecision(15);
    int R,C,K;cin >>R>>C>>K;
    //vvll board1(R+1,vector<ll>(C+1,0)), board2(R+1,vector<ll>(C+1,0)),board3(R+1,vector<ll>(C+1,0));
    vector<vector<vector<ll> > > board(4,vector<vector<ll> >(maxR, vector<ll>(maxR,0)));
    vvll item(R,vector<ll>(C,0));
    REP(i,K){
        int r,c; ll v;
        cin >> r>>c>>v;
        r--;c--;
        item[r][c] = v;
    }
    REP(i,R){
        REP(j,C){
            board[0][i+1][j+1] = max({board[0][i+1][j+1],board[0][i+1][j],board[0][i][j+1], board[1][i][j+1],board[2][i][j+1],board[3][i][j+1]});
            FOR(k,1,4){
                if(item[i][j] == 0){ //itemとる余地無し
                    board[k][i+1][j+1] = max(board[k][i+1][j+1], board[k][i+1][j]);
                }
                else{
                    if(k == 1){
                        board[k][i+1][j+1] = max({board[k][i+1][j+1], board[k][i+1][j], board[k-1][i+1][j] + item[i][j], board[0][i][j+1] + item[i][j], board[1][i][j+1] + item[i][j], board[2][i][j+1] + item[i][j] , board[3][i][j+1] + item[i][j]});
                    }
                    else{
                        board[k][i+1][j+1] = max({board[k][i+1][j+1], board[k][i+1][j], board[k-1][i+1][j] + item[i][j]});
                    }
                }
            }
        }
    }

    ll ans = 0;
    REP(i,4){
        ans = max(ans,board[i][R][C]);
    }
    cout << ans << endl;
}