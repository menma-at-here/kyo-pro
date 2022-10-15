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
const int max_n = 200010;
const ll mod = 998244353;
vector<ll> fac(max_n);
vector<ll> ifac(max_n);
vector<ll> m_mod(max_n);

ll N,M,K;
ll mpow(ll x, ll n){
    ll ans = 1;
    while(n != 0){
        if(n&1) ans = ans * x % mod;
        x = x * x % mod;
        n = n>>1;
    }
    return ans;
}

ll comb(ll a, ll b){
    if(a == 0 && b == 0) return 1;
    if(a < b || b < 0) return 0;
    ll tmp = ifac[b] * ifac[a-b] % mod;
    return tmp * fac[a] % mod;
}



int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
    cin>>N>>M>>K;
	//cout << fixed << setprecision(15);
    fac[0] = 1;
    ifac[0] = 1;
    m_mod[0] = 1;
    REP(i,N){
        fac[i+1] = fac[i] * (i+1) % mod; // fac[i] = n! % mod;
        ifac[i+1] = ifac[i] * mpow(i+1,mod-2) % mod; // ifac[i] = (i!) * pow(i, mod-2) % mod;
        m_mod[i+1] = m_mod[i] * (M-1) % mod;
    }

    ll ans = 0;
    for(ll i=0;i <= K; i++){
        ll now = 1;
        now = now* comb(N-1, i) % mod;
        now = now * M % mod;
        now = now * m_mod[N-i-1] % mod;
        ans += now;
        ans %= mod;
    }
    cout << ans << endl;
    
}