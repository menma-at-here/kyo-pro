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
const int max_n = 50;
const int max_m = 25*49;

int parent[max_n];
int Rank[max_n];

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
    
    if(Rank[x] < Rank[y]){
        parent[x] = y;
    }
    else{
        parent[y] = x;
        if(Rank[x] == Rank[y]) Rank[x]++;
    }
}

bool same(int x,int y){
    return find(x) == find(y);
}

int N,M;
int A[max_m], B[max_m];
int main(){
    cin >> N >> M;
    REP(i,M){
        cin >> A[i] >> B[i];
    }

    //init(N);
    int ans = 0;
    REP(i,M){
        init(N);
        int a_bridge, b_bridge;
        REP(k,M){
            int a = A[k]-1, b = B[k]-1;
            if(k != i){
                unite(a,b);
            }
            else{
                a_bridge = a;
                b_bridge = b;
            }
        }
        if(!same(a_bridge, b_bridge)){
            //cout << "not same:"<< find(a_bridge) << " " << find(b_bridge) << endl;
            ans++;
        }
        else{
            //cout << "same:" <<find(a_bridge) << " " << find(b_bridge) << endl;
        }
    }
    cout << ans << endl;
}

