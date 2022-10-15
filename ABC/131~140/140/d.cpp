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
    int N,K; cin >> N >> K;
    string S; cin >> S;
    int ans = 0;
    int count = 0;
    //int itr = 0;
    int turn = 0;
    REP(itr,N - 1){
        if(S[itr] == S[itr+1]){
            count++;
        }
        else{
            turn++;
        }
    }
    if(((turn+1) / 2) <= K){
        ans = count + turn;
    }
    else{
        ans = count + 2*K;
    }
    //cout << count << " " << turn << endl;
    cout << ans << endl;
}