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
const int maxn = 100000;
const int maxm = 200000;

template <class Abel> struct UnionFind{
    vector<int> parent;
    vector<int> rank;
    vector<Abel> diff_weight;

    UnionFind(int n,Abel sum_unity = 0){
        parent.resize(n); rank.resize(n); diff_weight.resize(n);
        REP(i,n){
            parent[i] = i; rank[i] = 0; diff_weight[i] = sum_unity;

        }
    }

    int  root(int x){
        if(parent[x] == x) return x;
        else{
            int r = root(parent[x]);
            diff_weight[x] += diff_weight[parent[x]];
            return parent[x] = r;
        }
    }

    bool issame(int x,int y){
        return root(x) == root(y);
    } 

    Abel weight(int x){
        root(x);
        return diff_weight[x];
    }

    bool unite(int x,int y,int w){
        w+= diff_weight[x];
        w-= diff_weight[y];
        x = root(x);
        y = root(y);

        if(x == y) return false;

        else{
            if(rank[x] < rank[y]) swap(x,y) , w = -w;
            if(rank[x] == rank[y]) rank[x]++;
            parent[y] = x;
            diff_weight[y] = w;
            return true;
        }
    }

    Abel diff(int x, int y){
        return weight(y) - weight(x);
    }

};

int N,M;
int L[maxm], R[maxm], D[maxm];
//vector<int> x(maxn,INF);

int main(){
    cin >> N >> M;
    UnionFind<int> uni(N, 0);

    bool ans = true;
    REP(i,M){
        int l,r,d;
        cin >> l >> r >> d;
        l--; r--;
        
        if(uni.issame(l,r)){
            if(uni.diff(l,r) != d){
                ans = false;
                //cout << l << " " << r << endl;
                break;
            }
        }
        else{
            uni.unite(l,r,d);
        }

    }
    cout << (ans ? "Yes" : "No") << endl;

}