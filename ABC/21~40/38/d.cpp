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

typedef pair <int,int> P;
vector<P> present;
int N;

bool compare(P a,P b){
    if(a.first == b.first){
        return a.second >b.second;
    }
    else{return a.first < b.first;}
}



int main(){
    cin >> N;
    REP(i,N){
        int w,h;
        cin >> w >> h;
        present.push_back(P(w,h));
    }
    sort(ALL(present),compare);

    int dp[N+2];
    int ans;
    REP(i,N+2){dp[i] = INF;}
    REP(i,N){
        *lower_bound(dp,dp + N, present[i].second) = present[i].second;
    }
    cout << lower_bound(dp,dp + N, INF) -dp << endl;
    
}