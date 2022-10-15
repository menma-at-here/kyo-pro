#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include<numeric>
#include<cmath>
#include<map>
#include<iomanip>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
using pll = pair<ll,ll>;
using pdd = pair<double,double>;
using vvi = vector<vector<int> >;
using vvll =  vector<vector<ll> >;
const ll maximanhattan = 1e9 + 1;

bool pair_second(pll a, pll b){
    return a.second < b.second;
}

int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(15);
    int N;cin>>N;
    //vector<pll> point(N);
    vector<ll> right(N), left(N);
    REP(i,N){
        ll x,y; cin>>x>>y;
        right[i] = x + y;
        left[i] = (1e9 - x) + y;

    }
    sort(ALL(right));
    sort(ALL(left));
    ll ans = max(right[N-1] - right[0], left[N-1] - left[0]);
    cout << ans << endl;

}

