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

const ll inf = 1LL << 60;

struct Sieve{
    //int N;
    //vector<bool> is_prime;
    vector<int> minprime;
    //vector<map<int,int> > reserve;
    vector<int>  primes;
    vector<ll> kosuu;

    Sieve(int N){
        minprime.resize(N+1,0);
        minprime[0] = minprime[1] = -1;
        kosuu.resize(N+1,0);
        kosuu[0] = 0;
        kosuu[1] = 1;
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

    //map<int,int> mp;
    void kosuulist(int N,map<int,ll> mp,int now){
        REP(i,primes.size()){
            map<int,ll> nowmp = mp;
            ll n = now;
            nowmp[primes[i]]++;
            n *= primes[i];
            if(n > N) break;
            else{
                if(kosuu[n] != 0 && kosuu[n] != 1) continue;
                ll plus = 1;
                for(auto k = begin(nowmp); k != end(nowmp); ++k){
                    const auto n = (k->second + 1);
                    plus *= n;
                }
                kosuu[n] = plus;
                kosuulist(N,nowmp,n);
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

    map<int,int> rekkyomap(int x){
        map<int,int> res;
        while(minprime[x] != -1){
            res[minprime[x]]++;
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
	ios_base::sync_with_stdio(false);
	//cout << fixed << setprecision(15);
    int N;cin>>N;
    /*Sieve sieve(N);
    ll ans = 1;
    sieve.furui(N);
    for (int i = 2;  i <= N ; i++){
        auto nowmap = sieve.rekkyomap(i);
        int now = 1;
        for(auto k = nowmap.begin(); k != nowmap.end(); k++){
            now *= (k->second + 1);
            //cout << k->first << " " <<  k->second<< endl;
        }
        ans += now * i;
    }
    /*vector<int> a = sieve.factorlist(4);
    REP(i,a.size()){
        cout << a[i] << endl;
    }*/
    //map<int,ll> mpmp;
    //sieve.kosuulist(N,mpmp,1);
    /*for(int i = 2; i <= N ; i++){
        ans += i * sieve.kosuu[i];
    }*/
    //auto mp = rekkyomap()

    ll ans = 0;
    for(ll j = 1; j <= N; j++){
        ll floor = N / j;
        ans += j * (floor+1)*floor / 2;
    }
    
    cout << ans << endl;
}
