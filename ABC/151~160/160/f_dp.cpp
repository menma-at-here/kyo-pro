#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include<numeric>
#include<cmath>
#include<map>
#include<queue>
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
const int maxn = 200005;

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

struct Combination{
    vector<ll> fact,ifact;
    Combination(int n): fact(n+1),ifact(n+1){
        fact[0] = 1;
        for(int i = 1; i<=n; i++)fact[i] = fact[i-1]*i % mod;
        ifact[n] = mpow(fact[n],mod-2);
        for(int i = n; i>= 1; i--){
            ifact[i-1] = ifact[i] * i % mod;
        }
    }

    ll comb(int n, int k){
        if(k < 0 || n < k)return 0;
        return fact[n]*ifact[k]%mod*ifact[n-k]%mod;
    }
};

Combination C(maxn);

struct DP{ //木dpにのせるモノイド
    mint dp; //
    int t;
    DP(mint d = 1, int tt = 0):dp(d),t(tt){}
    DP& operator+= (const DP &a){
        dp *= a.dp;
        dp *= C.comb(t + a.t, t);
        t += a.t;
        return *this;
    }

    DP operator- (const DP &a) const{ 
        DP res(*this);
        res.t -= a.t;
        res.dp /= a.dp;
        res.dp /= C.comb(res.t + a.t, res.t);
        return res;
    }

    DP addroot(){
        DP res(*this);
        res.t++;
        return res;
    }

    void process(){ //自分自身を含めて一つの部分木にする関数
        t++;
    }
};

struct Tree{
    int N;
    vector<vector<int> > G;
    //map<P, pll> mp;  mapは使わなくて良い
    //vector<pll> goukei; これもいらん

    Tree(){
        cin >> N;
        G.resize(N);
        //goukei.resize(N,pll(0,1));
        REP(i,N-1){
            int a,b; cin >>a>>b;
            a--; b--;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        //C.resize(100005);
    }

    DP dpvec[maxn];

    void dfs(int v, int p = -1){
        REP(i,G[v].size()){
            int next = G[v][i];
            if(next != p){
                dfs(next,v);
                dpvec[v] += dpvec[next].addroot();
            }
        }
        //return dp[v];
    }

    void bfs(int v, int p = -1){
        for(int next : G[v]){
            if(next == p)continue;
            DP d = dpvec[v] - dpvec[next].addroot();
            dpvec[next] += d.addroot();
            bfs(next,v);
        }
    }

};

int main(){
    Tree tree;
    tree.dfs(0);
    tree.bfs(0);
    REP(i,tree.N){
        cout << tree.dpvec[i].dp << endl;
    }

}