#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

ll D;
string Ns;

int main(){
    cin >> D;
    cin >> Ns;
    ll L = Ns.size();
    ll dpbool[L+1][D];
    ll dpdp[L+1][D];

    ll amari_bool = 0;
    REP(i,L+1){
        REP(j,D){
            dpbool[i][j] = 0;
            dpdp[i][j] = 0;
        }        
    }
    //dpdp[0][0] = 1;
    dpbool[0][0] = 1;
    REP(i,L){
        ll x = Ns[i] - '0';
        //cout << x;
        amari_bool = (amari_bool + x) % D;
        REP(k,D){
            if((amari_bool + D - k) % D == 0) dpbool[i+1][k] = 1;
        }
    }
    /*REP(i,L+1){
        REP(k,D){
            if(dpbool[i][k] == 1){cout << i << " " << k << endl;}
        }
    }*/
    //cout << endl << endl;

    
    for(ll i = 0; i < L; i++){
       for(ll j = 0; j < D; j++){
            ll dp0 = 0, dp1 = 0;
            REP(l, 10){
                dp0 += dpdp[i][(10*D+j-l) % D];
            }
            if (Ns[i] - '0' > 0){
                REP(k,Ns[i] - '0'){
                dp1 += dpbool[i][(10*D+j-k)%D];
                }
            }
            else {dp1 = 0;}
            dpdp[i+1][j] = dp0 + dp1;
            dpdp[i+1][j] %= mod;
            //cout << dpdp[i+1][j] << " ";
       }
       //cout << endl;
    }

    cout << (dpdp[L][0] + dpbool[L][0] - 1) % mod << endl;

}