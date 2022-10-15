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
    int N; cin>>N;
    vector<int> ans(N,0);
    FOR(x,1,100){
        FOR(y,1,100){
            FOR(z,1,100){
                int plus = x*x + y*y + z*z + x*y + y*z + z*x;
                if(plus <= N){
                    ans[plus-1]++;
                }
            }
        }
    }
    REP(i,N){
        cout<<ans[i]<<endl;
    }
}