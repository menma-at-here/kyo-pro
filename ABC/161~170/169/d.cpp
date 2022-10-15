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
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> pll;
const ll inf = 1LL << 60;
const int pp = 1e6+10;


int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	//cout << fixed << setprecision(15); 
    ll N; cin>>N;
    vector<bool> is_prime(pp+1,true);
    REP(i,pp+1){
        if(i == 0|| i == 1){
            is_prime[i] = false;
        }
        if(is_prime[i] == true){
            for(int k = 2*i; k <= pp; k+=i){
                is_prime[k] = false;
            }
        }
    }
    vector<int> prime(pp+1,0);
    int itr = 0;
    for(ll i = 2; i*i <= N; i++){
        if(is_prime[i]){
            while(N % i == 0){
                N /= i;
                prime[itr]++;
            }
            itr++;
            if(N == 1) break;
        }
    }
    if(N>1) {
        prime[itr]++;
        itr++;
    }
    
    int ans = 0;
    REP(i,itr){
        int k = 1;
        while(k * (k+1) / 2 <= prime[i]){
            k++;
        }
        k--;
        ans += k;
    }
    cout << ans << endl;
}