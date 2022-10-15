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
const ll inf = 1LL << 51;

int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(15);
    int A,B,Q; cin >>A>>B>>Q;
    vector<ll> S(A), T(B), ans(Q);
    REP(i,A)cin >> S[i];
    REP(i,B) cin >> T[i];
    //REP(i,Q) cin >> queri[i];
    S.push_back(-inf);
    S.push_back(-inf - 1);
    S.push_back(inf);
    S.push_back(inf+1);
    T.push_back(-inf);
    T.push_back(-inf - 1);
    T.push_back(inf);
    T.push_back(inf+1);
    

    
    sort(ALL(S));
    sort(ALL(T));

    REP(i,Q){
        ll mini = inf;
        ll q; cin >> q;
        auto s_pointer = lower_bound(ALL(S), q);
        auto t_pointer = lower_bound(ALL(T), q);
        ll bigs = *s_pointer;
        ll smalls = *prev(s_pointer);
        ll bigt = *t_pointer;
        ll smallt = *prev(t_pointer);

        auto nextt_p_big = lower_bound(ALL(T), bigs);
        ll bigmint = min(*nextt_p_big - bigs, bigs - *prev(nextt_p_big));
        mini = min(mini, bigs - q + bigmint);
        //cout << bigs - q + bigmint << endl;

        auto nextt_p_small = lower_bound(ALL(T), smalls);
        ll smallmint = min(*nextt_p_small - smalls, smalls - *prev(nextt_p_small));
        mini = min(mini, q - smalls + smallmint);
        //cout << q - smalls + smallmint << endl; 

        auto nexts_p_big = lower_bound(ALL(S), bigt);
        ll bigmins = min(*nexts_p_big - bigt, bigt - *prev(nexts_p_big));
        mini = min(mini, bigt - q + bigmins);
        //cout << bigt - q + bigmins << endl;

        auto nexts_p_small = lower_bound(ALL(S), smallt);
        ll smallmins = min(*nexts_p_small - smallt, smallt - *prev(nexts_p_small));
        mini = min(mini, q - smallt + smallmins);
        //cout << q - smallt + smallmins << endl;

        ans[i] = mini;
        //cout << endl;
    }
    REP(i,Q){
        cout << ans[i]<<endl;
    }
}

