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

struct Tree{
    int N;
    vector<vector<int> > G;
    map<P, pll> mp;
    vector<pll> goukei;

    Tree(){
        cin >> N;
        G.resize(N);
        goukei.resize(N,pll(0,1));
        REP(i,N-1){
            int a,b; cin >>a>>b;
            a--; b--;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        //C.resize(100005);
    }

    pll rec(int start,int next){
        if(G[next].size() == 1){
            return pll(1,1);  //pll(木の個数、何通りでわるか)
        }

        if(mp.find(pll(start,next)) == mp.end()){
            mp[pll(start,next)] = pll(1,1);
            REP(i,G[next].size()){
                int nnext = G[next][i];
                if(nnext != start){
                    pll nextpair = rec(next,nnext);
                    mp[pll(start,next)].first += nextpair.first;
                    mp[pll(start,next)].second = (mp[pll(start,next)].second * nextpair.second % mod) * mpow(nextpair.first,mod-2) % mod;
                }
            }
            mp[pll(start,next)].second *= mp[pll(start,next)].first;
            mp[pll(start,next)].second %= mod;
            
            //return mp[pll(start,next)];
        }
    
        
        return mp[pll(start,next)];
        
    }

    void bfs(int parent = -1, int kid = 0){
        queue<P> que;
        REP(i,G[kid].size()){
            pll start = rec(kid,G[kid][i]);
            goukei[kid].first += start.first;
            goukei[kid].second = goukei[kid].second * start.second % mod * C.ifact[start.first] % mod;
            //goukei[kid].second %= mod;
            que.push(P(kid,G[kid][i]));
        }
        goukei[kid].second *= C.ifact[goukei[kid].first];
        goukei[kid].second %= mod;
        
        while(!que.empty()){
            P now = que.front();que.pop();
            ll first = 0;
            ll second = 1;
            
            
        }
        
    }

    void solve(){

        Combination comb(N);

        /*REP(i,N-1){
            REP(k,G[i].size()){
                cout << G[i][k] << " ";
            }
            cout << endl;
        }*/

        REP(i,N){
            ll first = 0;
            mint second = 1;
            if(goukei[i].first != -1){
                first += goukei[i].first;
                second *= goukei[i].second;
            }
            else{
                REP(k,G[i].size()){
                    int nex = G[i][k];
                    pll res = rec(i,nex);
                    pll plus = rec(nex,i);
                    first += res.first;
                    second *= res.second;
                    goukei[i].first += res.first;
                }
            }
            
            //cout << first <<" "<< second << endl;
            mint ans = comb.fact[first] * second.inv();
            cout << ans << endl;
        }
        
    }
};

int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	//cout << fixed << setprecision(15);

    Tree tree;
    tree.solve();
}