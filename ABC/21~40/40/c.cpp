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
const ll inf = 1LL << 60;
int N;
vector<ll> A;
vector<ll> dp;

ll dpfunc(int place){
    if(place == 0) return 0;
    else if(place == 1) return llabs(A[1]-A[0]);

    if(dp[place] != -1) return dp[place];

    ll mini = min(dpfunc(place-1) + llabs(A[place] - A[place-1]), dpfunc(place-2) + llabs(A[place] - A[place-2]));
    return dp[place] = mini;

}

int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	//cout << fixed << setprecision(15);
    cin>>N;
    A.resize(N);
    REP(i,N){
        cin>>A[i];
    }
    dp.resize(N,-1);
    ll ans = dpfunc(N-1);
    cout<<ans<<endl;
}