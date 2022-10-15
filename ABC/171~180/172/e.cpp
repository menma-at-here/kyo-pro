#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include<numeric>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int max_n = 500010;
const ll mod = 1000000007;
vector<ll> fac(max_n);
vector<ll> ifac(max_n);

int N,M;
ll mpow(ll x, ll n){
    ll ans = 1;
    while(n){
        if(n % 2){
            ans = ans * x % mod;
        }
        x = x * x % mod;
        n >>= 1;
    }
    return ans;
}

ll comb(ll a, ll b){
    if(a == 0 && b == 0) return 1;
    if(a < 0 || b < 0) return 0;
    ll tmp = ifac[b] * ifac[a-b] % mod;
    return tmp * fac[a] % mod;
}

ll Perm(ll a, ll b){
    if(a == 0 && b == 0) return 1;
    if(a < 0 || b < 0) return 0;
    ll tmp = ifac[a-b] % mod;
    return tmp * fac[a] % mod;
}


int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	//cout << fixed << setprecision(15);
    fac[0] = 1;
    ifac[0] = 1;
    cin>>N>>M;
    if(N > M){
        cout << 0 << endl;
        return 0;
    }
    REP(i,M){
        fac[i+1] = fac[i] * (i+1) % mod; // fac[i] = n! % mod;
        ifac[i+1] = ifac[i] * mpow(i+1,mod-2) % mod; // ifac[i] = (i!) * pow(i, mod-2) % mod;
    }
    
    /*REP(i,6){
        //cout << fac[i] << " ";
        cout << mpow(i,mod-2)<<" ";
    }
    cout<<endl;
    REP(k,4){
        cout << ifac[k] << " ";
    }
    cout << endl;*/

    ll ans = 0;
    for(ll k = 0; k <= N; k++){
        ll tmp = Perm(M - k , N - k) * comb(N,k) % mod;
        //cout << tmp << endl;
        ans += ( k % 2 == 0 ? tmp : -tmp);
        ans %= mod;
    }
    ans = ans * Perm(M,N) % mod;

    cout << ans << endl;
    return 0;
    
    

}