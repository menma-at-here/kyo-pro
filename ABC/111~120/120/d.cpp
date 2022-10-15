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
const int max_n = 100000;
const int max_m = 100000;

ll parent[max_n];
ll Rank[max_n];
ll numberofgroup[max_n];

void init(ll n){
    REP(i,n){
        parent[i] = i;
        Rank[i] = 0;
        numberofgroup[i] = 1;
    }
}

ll find(ll x){
    if(x == parent[x]) return x;
    else{
        return parent[x] = find(parent[x]);
    }
}

void unite(ll x, ll y){
    x = find(x);
    y = find(y);
    if(x == y) return;
    
    if(Rank[x] < Rank[y]){
        parent[x] = y;
        numberofgroup[y] += numberofgroup[x];
    }
    else{
        parent[y] = x;
        if(Rank[x] == Rank[y]) Rank[x]++;
        numberofgroup[x] += numberofgroup[y];
    }
}

bool same(ll x,ll y){
    return find(x) == find(y);
}


ll N,M;
ll A[max_n], B[max_m];
ll ans[max_m+1];
int main(){
    cin >> N >> M;
    REP(i,M){
        cin >> A[i] >> B[i];
    }
    ans[M] = N * (N-1) / 2;
    init(N);
    REPR(i,M-1){
        ll a = A[i]-1;
        ll b = B[i]-1;
        if(same(a,b)){
            ans[i] = ans[i+1];
            unite(a,b);
        }
        else{
            ans[i] = ans[i+1] - numberofgroup[find(a)] * numberofgroup[find(b)];
            unite(a,b);
        }
    }
    REP(i,M){
        cout << ans[i+1] << endl;
    }
}