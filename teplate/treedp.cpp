#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include<numeric>
#include<cmath>
#include<map>
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
using vvii = vector<vector<int> >;
using vvll =  vector<vector<ll> >;
const ll mod = 1e9 + 7;
const int maxn = 200005;

const ll inf = 1LL << 60;

template <typename Abel>
struct DP{
    Abel dp;
    int t;
    DP& operator= (const DP &a){
        dp = a.dp;
        t = a.t;
        return *this;
    }

    DP& operator+=(const DP &a){
        //任意の処理
        return *this;
    }
    DP operator-(const DP &a)const{
        DP res(*this);
        //任意の処理
        return res;
    }  
    DP addroot(){
        DP res(*this);
        //任意の処理
        return res;
    }

};

template <typename Abel>
struct Tree{
    int N;
    vector<vector<int> > G;
    vector<DP<Abel> >  dpvec[maxn]; //辺に対応するdpの値
    DP<Abel> dpSum[maxn];  //bfsも含めた合計

    Tree(){

    }

    DP<Abel> dfs(int v, int p = -1){
        dpvec[v] = vector<DP<Abel> >(G[v].size());
        REP(i,G[v].size()){
            int next = G[v][i];
            if(next == p)continue;
            dpvec[v][i] = dfs(next,v);
            dpSum[v] += dpvec[v][i];
        }
        return dpSum[v].addroot(); //自分自身を含めた木を返す
    }


    void bfs(int v,const DP<Abel>& dpP = DP<Abel>(), int p = -1){
        if(p != -1){
            dpSum[v] += dpP;
        }
         REP(i,G[v].size()){
            int next = G[v][i];
            if(next == p){
                //dpvec[v][i] = dpP; なくてもよい？
                continue;
            }
            DP<Abel> d = dpSum[v] - dpvec[v][i];
            bfs(next, d.addroot(), v);
        }
        
    }
};

int main(){
    Tree<int> tree; //intの部分はいろいろ変えて
    tree.dfs(0);
    tree.bfs(0);
    REP(i,tree.N){
        cout << tree.dpSum[i].addroot().dp << endl;
    }
}