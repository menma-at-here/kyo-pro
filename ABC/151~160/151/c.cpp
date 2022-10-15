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
using vvi = vector<vector<int> >;
using vvll =  vector<vector<ll> >;

const ll inf = 1LL << 60;

int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	//cout << fixed << setprecision(15);
    int N,M;cin >>N>>M;
    vector<int> pena(N,0);
    vector<bool> AC(N,false);
    REP(i,M){
        int p; cin >> p;
        p--;
        string S; cin >>S;
        if(S == "WA"){
            if(AC[p] == false){
                pena[p]++;
            }
        }
        else{
            AC[p] = true;
        }

    }
    int ansp = 0;
    int ansac = 0;
    REP(i,N){
        if(AC[i]){
            ansac++;
            ansp += pena[i];
        }
        
    }
    cout << ansac << " " << ansp <<endl;
}