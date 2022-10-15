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
using ll = long long;
using P = pair<int,int>;
using pll = pair<ll,ll>;
using vvii = vector<vector<int> >;
using vvll =  vector<vector<ll> >;
const int numcon = 26;

const ll inf = 1LL << 60;

int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	//cout << fixed << setprecision(15);
    int D; cin>>D;
    vector<ll> C(numcon);
    vector<vector<ll> > S(D, vector<ll>(numcon)),last(numcon,vector<ll>(1,0));
    REP(i,numcon){
        cin>>C[i];
    }
    REP(i,D){
        REP(k,numcon){
            cin >> S[i][k];
        }
    }
    vector<ll> T(D);
    REP(i,D){
        cin >> T[i];
        T[i]--;
    }

    ll ans = 0;
    vector<ll> ansans(D);

    REP(i,D){
        ans += S[i][T[i]];
        last[T[i]].push_back(i+1);
        REP(k,numcon){
            auto itr = last[k].rbegin();
            ans -= C[k] * (i+1 - *itr);
        }
        ansans[i] = ans;
    }

    REP(i,D){
        cout << ansans[i] << endl;
    }
    
}