#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int N,M;
vector<int> A;
int main(){
    cin >>  N >> M;
    REP(i,M){
        int a;
        cin >> a;
        A.push_back(a);
    }
    int day = accumulate(ALL(A),0);
    if(N >= day){cout << N - day << endl;}
    else{cout << -1 << endl;}
}