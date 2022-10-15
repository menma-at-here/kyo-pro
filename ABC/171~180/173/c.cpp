#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include<numeric>
#include<cmath>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
using pll = pair<ll,ll>;
using vvii = vector<vector<int> >;
using vvll =  vector<vector<ll> >;

const ll inf = 1LL << 60;
int H,W,K; 

int black(vvii S,int bh,int bw){
    REP(i,H){
        if(bh & (1<<i)){
            REP(k,W){
                S[i][k] = 0;
            }
        }
    }
    REP(i,W){
        if(bw & (1 << i)){
            REP(l,H){
                S[l][i] = 0;
            }
        }
    }
    int res = 0;
    REP(i,H){
        REP(k,W){
            if(S[i][k] == 1)res++;
        }
    }

    return res;
}

int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	//cout << fixed << setprecision(15);
    cin>>H>>W>>K;
    vector<string> C(H);
    vector<vector<int> > board(H,vector<int>(W));
    REP(i,H){
        string s; cin >>s;
        REP(k,W){
            if(s[k] == '.'){
                board[i][k] = 0;
            }
            else board[i][k] = 1;
        }
    }
    int ans = 0;
    for(int bith = 0 ; bith < pow(2,H); bith++){
        for(int bitw = 0 ; bitw < pow(2,W); bitw++){
            if(black(board,bith,bitw) == K)ans++;
        }
    }

    cout<<ans<<endl;
}