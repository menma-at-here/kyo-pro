#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include<numeric>
#include<cmath>
#include <map>
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

const ll inf = 1LL << 60;
const ll mod = 1e9 + 7;
const int maxi = 1e6;

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
    return ans;
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
    }

    void furui(int N){
        for(int i = 2; i <= N; i++){
            if(minprime[i])continue;
            
            primes.push_back(i);
            minprime[i] = i;
            for(int k = 2*i; k<= N; k+=i){
                //is_prime[k] = false;
                if(minprime[k] == 0)minprime[k] = i;
                
            }
            
        }
    }

    vector<int> factorlist(int x){
        vector<int> res;
        while(minprime[x] != -1){
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
        if(list.size() == 0) return{};
        vector<P> res(1,P(list[0], 0));
        for(auto p : list){
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
	//ios_base::sync_with_stdio(false);
	//cout << fixed << setprecision(15);
    int n;
    cin >> n;
    Sieve sieve(n);
    sieve.furui(n);
    /*REP(i,n+1){
        printf("%d %d\n",i,sieve.minprime[i]);
    }*/
    vector<int> list = sieve.factorlist(n);
    
    vector<P> p = sieve.rekkyo(n);

    
}