#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include<numeric>
#include<cmath>
#include<map>
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
const int maxa = 1e6;

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
    ll shou = ans / mod;
    ll amari = ans % mod;
    return shou + amari;
}

struct Sieve{
    //int N;
    //vector<bool> is_prime;
    vector<int> minprime;
    //vector<map<int,int> > reserve;
    vector<int>  primes;

    Sieve(int N){
        minprime.resize(N+1,0);
        minprime[0] = minprime[1] = -1;
        for(ll i = 2; i <= N; i++){
            if(minprime[i])continue;
            
            primes.push_back(i);
            minprime[i] = i;
            for(int k = 2*i; k<= N; k+=i){
                //is_prime[k] = false;
                if(minprime[k] == 0)minprime[k] = i;
                
            }
            
        }
    }

    /*void furui(int N){
        for(int i = 2; i <= N; i++){
            if(minprime[i])continue;
            
            primes.push_back(i);
            minprime[i] = i;
            for(int k = 2*i; k<= N; k+=i){
                //is_prime[k] = false;
                if(minprime[k] == 0)minprime[k] = i;
                
            }
            
        }*/

    vector<int> factorlist(int x){
        vector<int> res;
        while(x != 1){
            res.push_back(minprime[x]);
            x /= minprime[x];
        }
        return res;
    }

    vector<P> rekkyo(int x){
        /*while(minprime[x] != 1){
            x /= minprime[x];
            reserve[x][minprime[x]]++;
        }*/
        vector<int> list = factorlist(x);
        if(list.size() == 0)  return{};
        vector<P> res(1,P(list[0], 0));
        for(int p : list){
            if(res.back().first == p){
                res.back().second++;
            }
            else{
                res.push_back(P(p,1));
            }
        }
        return res;
    }
    
};

int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	//cout << fixed << setprecision(15);
    int N; cin>>N;
    vector<ll> A(N);
    REP(i,N){
        ll a;
        cin >> a;
        A[i] = a;
    }
    
    Sieve sieve(maxa);
    //sieve.furui(maxa);
    //cout << sieve.rekkyo(8)[0].second<<endl;
    map<int,int> maxi;
    REP(i,N){
        vector<P> p = sieve.rekkyo(A[i]);
        /*REP(k,p.size()){
            cout<<p[k].first<<" "<<p[k].second<<endl;
        }*/
        for(auto k : p){
            maxi[k.first] = max(maxi[k.first], k.second);
        }
    }
    mint lcmm = 1;
    for(auto i : maxi){
        /*mint now = i.first;
        lcmm *= now.pow(i.second);*/
        REP(k,i.second){
            lcmm *= i.first;
        }
    }
    //cout << lcmm <<endl;
    mint ans = 0;
    REP(i,N){
        mint b = lcmm/A[i];
        ans += b;
    }
    cout<<ans<<endl;
    
}