#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include<numeric>
#include<cmath>
#include<map>
#include<iomanip>
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
using pdd = pair<double,double>;
using vvi = vector<vector<int> >;
using vvll =  vector<vector<ll> >;

int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(15);
    int N; cin >> N;
    vector<pll> Perm(N);
    REP(i,N){
        ll p; cin >> p;
        Perm[i] = P(p,i+1);
    }
    sort(ALL(Perm));
    reverse(ALL(Perm));
    multiset<ll> st;
    st.insert(0);
    st.insert(0);
    st.insert(N+1);
    st.insert(N+1);

    ll ans = 0;
    REP(i,N){
        ll fi = Perm[i].first;
        ll se = Perm[i].second;
        //st.insert(se);
        auto itr = st.lower_bound(se);
        //auto itrminus = itr--;
        ll w = *prev(itr,2);
        ll x = *prev(itr,1);
        ll y = *itr;
        ll z = *next(itr,1);
        ans += fi * ((z-y)*(se-x) + (y-se)*(x-w));
        st.insert(se);
    }
    cout << ans << endl;
}

