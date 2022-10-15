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
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> pll;
const ll mod = 1000000007;

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

ll gcd(ll a,ll b){
    if(a == 0 && b == 0) return 0;
    else if(a == 0) return b;
    else if(b == 0) return a;
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

int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	//cout << fixed < cin >> N;
    vector<int> A,B;
    int N; cin>>N;
    ll none = 0;
    map<pll,pll> iwashi;
    REP(i,N){
        ll a,b;
        cin >> a >> b;
        if(a == 0 && b == 0) none++;
        else if(a == 0){
            iwashi[pll(0,0)].second++;
        }
        else if(b == 0){
            iwashi[pll(0,0)].first++;
        }
        else{
            ll g = gcd(a,b);
            a = a/g;
            b = b/g;
            if(b < 0){  //全ての点のy座標を正に
                a = -a; b = -b;
            }
            //else if(b == 0 && a < 0)a = -a;
            if(a<0){
                ll tmp = a;
                a = b;
                b = -tmp;
                iwashi[pll(a,b)].second++;
            }
            else{
                iwashi[pll(a,b)].first++;
            }
        }
    }
    ll ans = 1;
    for(auto i : iwashi){
        //i->
        ll now = (mpow(2,i.second.first) + mpow(2,i.second.second)-1) % mod;
        ans = ans* now % mod;
    }
    ans--;
    ans += none;
        
    cout << (ans+mod) % mod << endl;
    //cout << __gcd(10,-10) << endl;
}