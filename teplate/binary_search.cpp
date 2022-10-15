#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include<numeric>
#include <climits>
#define REP(i, n) for(ll i = 0; i < n; i++)
#define REPR(i, n) for(ll i = n; i >= 0; i--)
#define FOR(i, m, n) for(ll i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const ll inf = 1L<<60;

class  binary_search{
public:
    vector<ll> H;
    vector<ll> S;
    
    binary_search(ll n){
        H.resize(n);
        S.resize(n);
        REP(i,n){
            cin >> H[i] >> S[i];
        }
    }

    bool check(ll mid){
        ll n = H.size();
        vector<ll> second(n);
        bool flag = true;
        
        return (flag);
    }

    void binary(ll start, ll end){
        ll ng = start - 1; ll ok = end;
        while(ok - ng > 1){
            ll mid = (ng + ok) / 2;
            (check(mid) ? ok : ng) = mid;
        }
        cout << ok << endl;
    }
};