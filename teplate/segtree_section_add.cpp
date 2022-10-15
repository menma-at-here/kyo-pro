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

struct Segment_Tree{  //区間和の遅延評価セグ木
    int N;
    vector<ll> data,lazy;

    Segment_Tree(vector<ll> vec){
        int n_ = vec.size();
        N = 1;
        while(n_ > N){
            N *= 2;
        }
        data.resize(2*N - 1);
        lazy.resize(2*N - 1, 0);
        REP(i,n_){
            int q = i + N -1;
            data[q] = vec[i];
        }
        for(int i = N -2; i >= 0; i--){
            data[i] = data[2*i + 1] + data[2*i + 2];
        }
    }

    void eval(int k, int l, int r){  //遅延評価　k: k番目のノードについての遅延評価  
        if(lazy[k] != 0){
            data[k] += lazy[k];

            if(r - l > 1){
                lazy[2*k + 1] += lazy[k]/2;
                lazy[2*k + 2] += lazy[k]/2; 
            }
            lazy[k] = 0;
        }
    }

    void add_sub(int a,int b, ll x, int k, int l, int r){ //[a,b)間の区間加算
        if(r <0) r = N;
        eval(k,l,r);  //遅延評価を行う

        if(b <= l || r <= a){ //もし[l,r)と[a,b)が交わらない ->なんもしない
            return;
        }
        else if(a <= l && r <= b){
            lazy[k] += (r - l) * x;
            eval(k,l,r);
        }
        else{
            add_sub(a, b, x, 2*k+1, l, (l+r)/2);
            add_sub(a, b, x, 2*k+2, (l+r)/2, r);
            data[k] = data[2*k+1] + data[2*k+2];
        }

    }

    void add(int a,int b, ll x){
        add_sub(a,b,x,0,0,N);
    }

    ll getsum_sub(int a, int b, int k, int l, int r){
        if(b <= l || a >= r){
            return 0; //maxに絶対ならない値を返す？
        }
        
        eval(k,l,r); //ここで遅延評価
        if(a <= l && r <= b){
            return data[k];
        }
        else{
            ll chl = getsum_sub(a, b, 2*k + 1, l, (l+r) / 2);
            ll chr = getsum_sub(a, b, 2*k + 2, (l+r) / 2, r);
            return chl + chr;
        }
    }

    ll getsum(int a,int b){
        return getsum_sub(a, b, 0, 0, N);
    }
};