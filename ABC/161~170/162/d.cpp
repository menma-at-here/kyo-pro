#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <time.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

const ll Max_N = 4000;
ll N;
string S;
int R[Max_N], G[Max_N], B[Max_N];

int main(){
    cin >> N;
    cin >> S;
    ll r = 0,g = 0, b = 0;
    REP(i,N){
        if(S[i]== 'R'){
            R[r] = i;
            r++;
        }
        else if(S[i] == 'G'){
            G[g] = i;
            g++;
        }
        else if(S[i] == 'B'){
            B[b] = i;
            b++;
        }
    }
    ll count = 0;
    if(!(r == 0 || g == 0 || b == 0)){
        /*REP(i,r){
            REP(k,g){
                REP(j,b){
                    int rg = abs(R[i] - G[k]);
                    int gb = abs(G[k] - B[j]);
                    int br = abs(B[j] - R[i]);
                    if(rg == gb || gb == br || br == rg){
                        count++;
                        if(rg == gb)
                }
            }
        }*/
        REP(i,N-2){
            FOR(k,1,(N + 1 -i)/2){
                if(S[i] != S[i+k] && S[i+k] != S[i+2*k] && S[i] != S[i+2*k]){
                    count++;
                }
            }
        }

        ll sum = r * g * b;
        cout << sum - count << endl;
    }
    else{cout << 0 <<endl;}

}