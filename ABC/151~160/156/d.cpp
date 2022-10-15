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
const ll mod = 1e9 + 7;

const ll inf = 1LL << 60;

struct mint{
    ll x;
    mint(ll x = 0): x((x % mod + mod)%mod){}

    
    mint& operator+=(const mint a){
        if((x += a.x) >= mod) x -= mod;
        return *this;
    }
    mint& operator-=(const mint a){
        if((x += mod-a.x) >= mod)  x -= mod;
        return *this;
    }
    mint& operator*=(const mint a){
        (x *= a.x) %= mod;
        return *this;
    }
    
    mint operator+(const mint a) const{ //クラスのメンバを変更しない
        mint res(*this);
        return res+=a;
    }
    mint operator-(const mint a) const{ //クラスのメンバを変更しない
        mint res(*this);
        return res-=a;
    }
    mint operator*(const mint a) const{ //クラスのメンバを変更しない
        mint res(*this);
        return res*=a;
    }

    mint pow(ll n)const{
        if(n == 0)return 1;
        mint a = pow(n>>1);
        a *= a;
        if(n & 1)a *= (*this);
        return a;
    }

    mint inv() const{
        return pow(mod-2);
    }
    mint& operator/=(const mint a){
        return (*this) *= a.inv();
    }
    mint operator/(const mint a)const{
        mint res(*this);
        return res/=a;
    }
    
};

ostream& operator<<(ostream &os, const mint &m){
    os << m.x;
    return os;
}

struct Combination{
    vector<mint> fact,ifact;
    Combination(int n): fact(n+1),ifact(n+1){
        fact[0] = 1;
        for(int i = 1; i<=n; i++)fact[i] = fact[i-1]*i;
        ifact[n] = fact[n].inv();
        for(int i = n; i>= 1; i--){
            ifact[i-1] = ifact[i] * i;
        }
    }

    mint comb(int n, int k){
        if(k < 0 || n < k)return 0;
        return fact[n]*ifact[k]*ifact[n-k];
    }
};

int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	//cout << fixed << setprecision(15);
    ll n;
    int a,b; cin >>n>>a>>b;
    mint ans;
    mint two = 2;
    mint nca = 1, ncb = 1;
    for(int i = 1; i <= a; i++){
        nca *= (n-i+1);
        nca /= i;
    }
    for(int i = 1; i <= b; i++){
        ncb *= (n-i+1);
        ncb /= i;
    }
    ans = two.pow(n) - 1 - nca - ncb;

    cout << ans << endl;

}