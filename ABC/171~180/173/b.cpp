#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include<numeric>
#include<cmath>
#include <map>
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
	//ios_base::sync_with_stdio(false);
	//cout << fixed << setprecision(15);
    int N; cin>>N;
    map<string,int> ans;
    REP(i,N){
        string S;
        cin>>S;
        ans[S]++;
    }
    printf("AC x %d\n", ans["AC"]);
    printf("WA x %d\n", ans["WA"]);
    printf("TLE x %d\n", ans["TLE"]);
    printf("RE x %d\n", ans["RE"]);
}