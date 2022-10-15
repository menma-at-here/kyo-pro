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

const ll inf = 1LL<<60;

int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(15);

    int X,Y,Z,K;cin>>X>>Y>>Z>>K;
    vector<ll> A(X+1),B(Y+1),C(Z+1);
    REP(i,X){
        cin >> A[i];
    }
    REP(i,Y){
        cin >> B[i];
    }
    REP(i,Z){
        cin >> C[i];
    }
    A[X] = B[Y] = C[Z] = -inf;
    sort(ALL(A),greater<ll>());
    sort(ALL(B),greater<ll>());
    sort(ALL(C),greater<ll>());
    
    vector<ll> ans_long,ans;
    REP(i,Y){
        REP(k,Z){
            ans_long.push_back(B[i] + C[k]);
        }
    }
    sort(ALL(ans_long),greater<ll>());
    int mini = min(Y*Z,K);
    vector<ll> BC(mini);
    REP(i,mini)BC[i] = ans_long[i];
    
    REP(i,X){
        REP(k,mini){
            ans.push_back(A[i] + BC[k]);
        }
    }
    
    sort(ALL(ans),greater<ll>());

    REP(i,K){
        cout << ans[i] << endl;
    }



}

