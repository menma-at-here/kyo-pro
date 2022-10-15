#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include<numeric>
#include<cmath>
#include<map>
#include<set>
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

struct SegmentTree{ //集合を返すやつ
    int N;
    vector<map<char,int> > dat;
    SegmentTree(int n_){
        N = 1;
        while(N < n_) N *= 2;
        dat.resize(2*N-1);
    }

    void update_init(int q, int a){
        q  = q + N - 1;
        dat[q][a]++;
        while(q>0){
            q = (q-1)/2;
            dat[q][a]++;
        }
    }

    void update(int q, char a){
        q  = q + N - 1;
        char old = dat[q].begin()->first;
        dat[q].erase(old);
        dat[q][a]++;
        while(q>0){
            q = (q-1)/2;
            if(dat[q][old] == 1)dat[q].erase(old);
            else dat[q][old]--;
            dat[q][a]++;
        }

    }

    set<char> queri(int a, int b,int k, int l, int r){ //[a,b)の文字数を調べる kは節点
        if(r <= a || b <= l){
            set<char> st; return st;
        }
        if(a <= l && r <= b){
            set<char> st;
            for(auto i = dat[k].begin(); i != dat[k].end(); i++){
                st.insert(i->first);
            }
            return st;
        }
        else{
            set<char> stl = queri(a,b, k*2+ 1, l, (l+r)/2);
            set<char> str = queri(a,b,k*2 + 2, (l+r)/2, r);
            for(auto i = str.begin(); i != str.end(); i++){
                stl.insert(*i);
            }
            return stl;
        }
    }
};

struct Segment_Tree{
    int N;
    vector<int> data;
    Segment_Tree(int n_){
        N = 1;
        while(N < n_) N *= 2;
        data.resize(2*N-1);
    }

    void update(int q, int a){
        q = q + N -1;
        data[q] = a;
        while(q > 0){
            q = (q-1)/2;
            data[q] = ;
        }
    }

    int queri(int a,int b, int k, int l, int r){
        
    }
};