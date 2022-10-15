#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include<numeric>
#include<cmath>
#include<bitset>
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

int N;
ll mpow(ll x, ll n,ll mod){
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

int func(ll n,ll wari){
    int count = 1;
    while(n % wari != 0){
        ll amari = n % wari;
        n = amari;
        wari = bitset<64>(amari).count();
        count++;
    }
    return count;
}

int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	//cout << fixed << setprecision(15);
    int N;cin>>N;
    string X; cin>>X;
    ll bit = 0;
    ll popcount = 0;
    ll popminus = 0;
    REP(i,X.length()){
        if(X[i] == '1')bit++;
    }
    REP(i,N){
        if(X[i] == '1'){
            popcount = (popcount + mpow(2,N-i-1,bit+1))%(bit+1);
            if(bit > 1) popminus = (popminus + mpow(2,N-i-1,bit-1))%(bit-1);
        }
    }
    vector<ll> ans(N,0);

    if(bit <= 1){
        ll x;
        REP(i,N){
            if(X[i] == '0'){
                x =(popcount + mpow(2,N-1-i,bit+1)%(bit+1));
                ans[i] = func(x,bit+1);
            }
            else{
                ans[i] = 0;
            }
        }
        REP(i,N){
            cout<<ans[i]<<endl;
        }
        return 0;
        
    }
    else{
        REP(i,N){
        ll x;
        if(X[i] == '0'){
            x = popcount + mpow(2,N-1-i,bit+1);
            ans[i] = func(x,bit+1);
        }
        else{
            x = (popminus + (bit-1) - mpow(2,N-1-i,bit-1)) % (bit-1);
            ans[i] = func(x,bit-1);
        }  
    }

    REP(i,N){
        cout<<ans[i]<<endl;
    }
    }
    

}