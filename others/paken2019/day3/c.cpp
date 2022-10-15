#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <functional>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
const int maxn = 100;
const int maxm = 100;

int N,M;
ll A[maxn][maxm];
int main(){
    cin >> N >> M;
    REP(i,N){
        REP(j,M){
            ll a; cin >> a;
            A[i][j] = a;
        }
    }
    ll maxi = 0;
    ll ans = 0;
    //vector<int> a;
    for(int i = 0; i < M; i++){
        for(int j = i+1; j < M; j++){
            ll now = 0;
            for(int k = 0; k < N; k++){
                now += max(A[k][i], A[k][j]);
            }
            maxi = max(maxi,now);
        }

    }
    cout << maxi << endl;
}