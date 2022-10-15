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

const ll inf = 1LL << 60;

int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	//cout << fixed << setprecision(15);
    ll N,M,K; cin>>N>>M>>K;
    vector<ll> A(N),B(M);
    vector<ll> suma(N+1,0),sumb(M+1,0);
    REP(i,N){
        cin >> A[i];
        suma[i+1] = suma[i] + A[i];
    }
    REP(i,M){
        cin >> B[i];
        sumb[i+1] = sumb[i] + B[i];
    }
    int maxi = 0;
    REP(i,N+1){
        ll now = K - suma[i];
        if(now < 0) break;
        else{
            int itr = upper_bound(ALL(sumb),now) - sumb.begin() - 1;
            maxi = max(maxi,i + itr);
        }
    }

    cout << maxi << endl;
}