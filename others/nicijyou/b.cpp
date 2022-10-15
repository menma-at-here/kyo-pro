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
typedef vector<vector<int> > vvi;
typedef vector<vector<ll> > vll;
const ll inf = 1LL << 60;

int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	//cout << fixed << setprecision(15);
    ll A,V,B,W;cin>>A>>V>>B>>W;
    ll T; cin>>T;
    if(A<B) swap(A,B);
    ll kyori = A-B;
    ll chi = V-W;
    if(chi == 0 && kyori != 0){
        cout<<"NO" << endl;
        return 0;
    }
    cout << (kyori > T*chi ? "NO" : "YES") <<endl;

}