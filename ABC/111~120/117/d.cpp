#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include<numeric>
#include<cmath>
#include<map>
#include<iomanip>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
using pll = pair<ll,ll>;
using pdd = pair<double,double>;
using vvi = vector<vector<int> >;
using vvll =  vector<vector<ll> >;
const ll inf = 1LL<<60;

ll mpow(ll x, ll n){
    ll ans = 1;
    while(n){
        if(n % 2){
            ans = ans * x;
        }
        x = x * x;
        n >>= 1;
    }
    return ans;
}

int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(15);
    ll N,K; cin >>N>>K;
    vector<ll> binary(64,0); //1が立っている個数を数える
    vector<ll> A(N);
    REP(i,N){
        ll a; cin >> a;
        A[i] = a;
        int itr = 0;
        while(a){
            if(a & 1)binary[itr]++;
            a >>= 1;
            itr++;
        }
    }
    int itrk = 1;
    ll k_ = 1;
    while(k_ < K){
        k_ *= 2;
        itrk++;
    }
    vector<vector<ll> > equal(2,vector<ll>(itrk+1,-inf)), smaller(2,vector<ll>(itrk+1,-inf));
    equal[0][itrk] = 0;
    ll ans = 0;
    for(int itr = 63; itr >= itrk; itr--){
        ans += binary[itr] * mpow(2,itr);
    }
    bool smallerflag = false;
    ll nowk = K;

    for(int itr = itrk - 1; itr >= 0; itr--){
        if(nowk & (1LL << itr)){
            equal[1][itr] = equal[(nowk >> (itr+1)) & 1][itr+1] + (N - binary[itr]) * mpow(2,itr);
        }
        else{
            equal[0][itr] = equal[(nowk >> (itr+1)) & 1][itr+1] + binary[itr] * mpow(2,itr);
        }
    }

    for(int itr = itrk - 1; itr >= 0; itr--){
        if(nowk & (1LL<<itr)){
            smaller[1][itr] = max({smaller[1][itr+1], smaller[0][itr+1], }) + (N - binary[itr]) * mpow(2,itr);
            smaller[0][itr] = max({smaller[1][itr+1], smaller[0][itr+1], equal[(nowk >> (itr+1)) & 1][itr+1]}) + binary[itr] * mpow(2,itr);
        }
        else{
            smaller[1][itr] = max(smaller[1][itr+1], smaller[0][itr+1]) + (N - binary[itr]) * mpow(2,itr);
            smaller[0][itr] = max(smaller[1][itr+1], smaller[0][itr+1]) + binary[itr] * mpow(2,itr);

        }
    }

    ans += max({smaller[1][0], smaller[0][0], equal[1][0], equal[0][0]});
    cout << ans << endl;

    
}

