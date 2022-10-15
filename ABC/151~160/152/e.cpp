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
const ll mod = 1e9 + 7;

ll gcd(ll a,ll b){
    if(a == 0 && b == 0) return 0;
    else if(a == 0|| b == 0) return 1;
    else{
        if(a < 0) a = -a;
        if(b < 0) b = -b;
        if(a < b) swap(a,b);
        while(true){
            ll p = a % b;
            a = b;
            b = p;
            if(p == 0)break;
        }
        return a;
    }
}

ll lcm(ll a,ll b){
    ll g = gcd(a,b);
    ll ans = a / g * b;
    //cout << ans << endl;
    ll shou = ans / mod;
    ll amari = ans % mod;
    return amari;
}

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

int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	//cout << fixed << setprecision(15);
    int N;cin>>N;
    ll A[N];
    REP(i,N){
        cin>>A[i];
    }
    ll lcm_all = 1;
    ll lcm_now = 1;
    REP(i,N){
        lcm_all = lcm(lcm_all,A[i]);
        //ll amari = lcm_all % mod;
        //ll shou = lcm_all / mod;
        //lcm_all = amari;// + shou;
        cout << lcm_all << endl;
    }
    ll ans = 0;
    REP(i,N){
        ans  += lcm_all * mpow(A[i],mod-2);
        ans %= mod;
    }

    cout << ans << endl;
}