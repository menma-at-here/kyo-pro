#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include<numeric>
#include<cmath>
#include<queue>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> pll;
const ll inf = 1LL << 60;

int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	//cout << fixed << setprecision(15);
    int N,M; cin>>N>>M;
    priority_queue<ll> A;
    REP(i,N){
        ll a;cin>>a;
        A.push(a);
    }
    REP(i,M){
        int top = A.top();A.pop();
        top /= 2;
        A.push(top);
    }
    ll ans = 0;
    REP(i,N){
        ll a = A.top(); A.pop();
        ans += a;
    }
    cout<<ans<<endl;
}