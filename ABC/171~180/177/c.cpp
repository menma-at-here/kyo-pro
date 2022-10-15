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
const ll mod = 1e9 + 7;

int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(15);
    int N; cin >> N;
    vector<ll> A(N),ruiseki(N+1,0);
    REP(i,N){
        cin >> A[i];
        ruiseki[i+1] = ruiseki[i] + A[i];
        ruiseki[i+1] %= mod;
    }
    ll ans = 0;
    for(int i = 1; i < N; i++){
        ans += ruiseki[i] * A[i];
        ans %= mod;
    }

    cout << ans << endl;
}

