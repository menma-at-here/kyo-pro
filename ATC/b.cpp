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
const int Max_q = 200000;
const int Max_n = 100000;

int N,Q;
int P[Max_q],A[Max_q], B[Max_q];
int parent[Max_n], Rank[Max_n];

void init(int n){
    REP(i,n){
    parent[i] = i;
    Rank[i] = 0;
    }
}

int find(int x){
    if(x == parent[x]) return x;
    else{
        return parent[x] = find(parent[x]);
    }
}

void unite(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return;
    else{
        if(Rank[x] < Rank[y]) parent[x] = y;
        else{
            parent[y] = x;
            if(Rank[x] == Rank[y]) Rank[x]++;
        }
    }
}

bool same(int x, int y){
    return find(x) == find(y);
}


int main(){
    cin >> N >> Q;
    REP(i,Q){
        cin >> P[i] >> A[i] >> B[i];
    }
    init(N);
    
    REP(i,Q){
        int p = P[i];
        int a = A[i];
        int b = B[i];
        if(p == 0){
            unite(a,b);
        }
        else{
            cout << (same(a,b) ? "Yes" : "No") << endl;
        }
    }
}