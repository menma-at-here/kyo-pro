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
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> pll;
const ll inf = 1LL << 60;
const ll comp = 1e18;

int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	//cout << fixed << setprecision(15);
    ll N; cin>>N;
    vector<ll> A(N);
    REP(i,N){   
        cin>>A[i];
        if(A[i] == 0){
            cout << 0 << endl;
            return 0;
        }
    }
    ll ans = 1;
    bool flag = true;
    REP(i,N){
        if(log10(ans) + log10(A[i]) > 18) {
            flag = false; break;
        }
        ans *= A[i];
        if(ans > comp){
            flag = false; break;
        }
    }
    cout<<(flag ? ans : -1) << endl;
}