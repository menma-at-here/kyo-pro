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
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> pll;
typedef vector<vector<int> > vvi;
typedef vector<vector<ll> > vll;
const ll inf = 1LL << 60;



int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	//cout << fixed << setprecision(15);
    int N;cin>>N;
    vector<int> A(N);
    int count_1 = 0;
    REP(i,N){
        cin>>A[i];
        if(A[i] == 1)count_1++;
    }

    if(count_1 > 0){
        if(count_1 == 1){
            cout << 1 << endl;
            return 0;
        }
        else{
            cout << 0 << endl;
            return 0;
        }
    }
    sort(ALL(A));

    vector<vector<int> > G(N);
    vector<bool> seen(N,false);
    REP(i,N){
        for(int k = 2; k*k <= A[i]; k++){
            if(A[i] % k == 0){
                G[i].push_back(k);
                G[i].push_back(A[i] / k);
            }
        }
    }

    int ans = 0;
    REP(i,N){
        if(A[lower_bound(ALL(A),A[i]) + 1 - A.begin()] == A[i]) continue;
        bool flag = true;
        REP(k,G[i].size()){
            if(binary_search(ALL(A), G[i][k])) flag = false;
        }
        if(flag) ans++;

    }
    cout << ans << endl;
}