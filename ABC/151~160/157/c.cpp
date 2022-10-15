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
    int N,M; cin>>N>>M;
    vector<int> S(M),C(M);
    vector<int> exist(N,-1);
    bool flag = true;
    REP(i,M){
        int s,c; cin>>s>>c;
        if(exist[s-1] == -1){
            exist[s-1] = c;
        }
        else{
            if(exist[s-1] == c)continue;
            else{
                flag = false; break;
            }
        }
    }
    if(!flag || ( N > 1 &&exist[0] == 0)){
        cout << -1 <<endl;
        return 0;
    }
    
    REP(i,N){
        if(exist[i] == -1){
            if(i == 0 && N > 1)exist[i] = 1;
            else exist[i] = 0;
        }
    }
    int ans = 0;
    REP(i,N){
        ans += exist[i] * pow(10,N-i-1);
    }
    cout<<ans<<endl;
}