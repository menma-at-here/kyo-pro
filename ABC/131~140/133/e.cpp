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
using ll = long long;
using P = pair<int,int>;
using pll = pair<ll,ll>;
using vvi = vector<vector<int> >;
using vvll =  vector<vector<ll> >;
const ll inf = 1LL << 60;
const ll mod = 1e9 + 7;

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

    mint operator==(const mint a) const{
        return x == a.x;
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

int N,K;
vector<vector<int> > G;
vector<P> flag;

/*int bfs2(int a){
    queue<P> que;
    que.push(P(a,0));
    int color = K;
    
    while(!que.empty()){
        P now = que.front(); que.pop();
        REP(k,G[now.first].size()){
            P next = P(G[now.first][k], now.second+1);
            if(flag[next.first] != -1)color--;
            if(color <= 0)return -1;
            if(next.second <= 1)que.push(next);
        }
    }

    return color;
}

mint bfs(int s){
    mint ans = 1;
    //flag[s] = K;
    queue<int> que;
    que.push(s);
    while(!que.empty()){
        int now = que.front(); que.pop();
        int mul = bfs2(now);
        if(mul == -1)return 0;

        flag[now] = mul;
        ans *= (mint)mul;
        REP(i,G[now].size()){
            int next = G[now][i];
            if(flag[next] == -1){
                que.push(next);
            }
        }
    }
    return ans;
}*/

void bfs(int s){
    queue<int> que;
    que.push(s);
    while(!que.empty()){
        int now = que.front(); que.pop();
        REP(i,G[now].size()){
            int next = G[now][i];
            if(flag[next].first == 0){
                flag[now].first++;
                flag[next].first++;
                flag[next].second += flag[now].first;
                que.push(next);
            }
        }
    }
}

int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	//cout << fixed << setprecision(15);
    cin>>N>>K;
    //mint ans = 0;
    G.resize(N);
    flag.resize(N,P(0,0));
    REP(i,N-1){
        int a,b;
        cin>>a>>b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    bfs(0);

    mint ans = 1;
    REP(i,N){
        ans *= (K - flag[i].second);
    }
    
    cout << ans << endl;
    //cout <<(ans == 0 ?  )
}