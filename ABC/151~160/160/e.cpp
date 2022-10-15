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

int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(15);
    int X,Y,A,B,C;cin>>X>>Y>>A>>B>>C;
    vector<ll> P(A),Q(B),R(C);
    REP(i,A)cin>>P[i];
    REP(i,B)cin>>Q[i];
    REP(i,C)cin>>R[i];
    sort(ALL(P),greater<ll>());
    sort(ALL(Q),greater<ll>());
    sort(ALL(R),greater<ll>());

    ll now = 0, ans = 0;
    REP(i,X) now += P[i];
    REP(i,Y) now += Q[i];
    int itrp = X - 1, itrq = Y - 1, itrr = 0;
    while(true){
        if(P[itrp] > Q[itrq]){
            if(R[itrr] > Q[itrq]){
                now += R[itrr] - Q[itrq];
                itrr++;
                itrq--;
            }
            else break;
        }
        else{
            if(R[itrr] > P[itrq]){
                now += R[itrr] - P[itrq];
                itrr++;
                itrp--;
            }
            else break;
        }
    }
    cout << now << endl;
}

