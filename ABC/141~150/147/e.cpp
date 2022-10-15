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
using pdd = pair<double,double>;
using vvi = vector<vector<int> >;
using vvll =  vector<vector<ll> >;
const int grid = 80;
const int maxa = 80;
const int mg = 6400;

int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(15);
    int H,W; cin >>H>>W;
    vector<vector<vector<bool> > > G(H+1,vector<vector<bool> >(W+1,vector<bool>(2 * mg + 1,false))); // 2 は-と+に伸びる感じ
    /*REP(i,H+1){
        G[i][0][mg] = true;
    }
    REP(i,W+1){
        G[0][i][mg] = true;
    }*/
    G[1][0][mg] = true;
    G[0][1][mg] = true;
    vector<vector<int> > A(H,vector<int>(W)), B(H,vector<int>(W)), diff(H,vector<int>(W));
    REP(i,H){
        REP(j,W){
            cin >> A[i][j];
        }
    }
    REP(i,H){
        REP(j,W){
            cin >> B[i][j];
        }
    }
    REP(i,H){
        REP(j,W){
            diff[i][j] = abs(A[i][j] - B[i][j]);
            //cout << diff[i][j] << " ";
        }
        //cout << endl;
    }

    REP(i,H){
        REP(j,W){
            REP(k, 2 * mg+1){
                if((k - diff[i][j] >= 0) && (G[i+1][j][k - diff[i][j]] == true)){
                    G[i+1][j+1][k] = true;
                }
                if((k + diff[i][j] <= 2*mg) && (G[i+1][j][k + diff[i][j]] == true)){
                    G[i+1][j+1][k] = true;
                }                
            }

            REP(k, 2 * mg+1){
                if((k - diff[i][j] >= 0) && (G[i][j+1][k - diff[i][j]] == true)){
                    G[i+1][j+1][k] = true;
                }
                if((k + diff[i][j] <= 2*mg) && (G[i][j+1][k + diff[i][j]] == true)){
                    G[i+1][j+1][k] = true;
                }                
            }
            
        }
    }

    int ans = INF;
    REP(i,2*mg+1){
        if(G[H][W][i]){
            //cout << i << endl;
            ans = min(ans, abs(mg - i));
        }
    }
    cout << ans << endl;
}

