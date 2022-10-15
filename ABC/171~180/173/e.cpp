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
using vvii = vector<vector<int> >;
using vvll =  vector<vector<ll> >;
const ll mod = 1e9 + 7;

const ll inf = 1LL << 60;

int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	//cout << fixed << setprecision(15);
    priority_queue<ll> plus;
    priority_queue<ll> minus;
    //priority_queue<ll> zero;
    vector<ll> vm;
    int zero = 0;
    int N,K; cin>>N>>K;
    ll ans = 1;
    REP(i,N){
        ll a; cin>>a;
        if(a > 0)plus.push(a);
        else if(a<0){minus.push(-a);vm.push_back(-a);}
        else zero++;
    }
    sort(ALL(vm));

    if(N - zero < K || (N - zero == K && minus.size() % 2 == 1 && zero >= 1) || (K % 2 == 1 && plus.size() == 0 && zero>= 1)) {
        ans = 0;
        cout<<ans<<endl;
        return 0;
    }
    else if(K % 2 == 1 && plus.size() >= 1){
        ll now = plus.top(); plus.pop();
        ans *= now;
        K--;
    }
    else if(plus.size() == 0){
        if(zero>= 1 && K % 2 == 1)ans = 0;
        else if(K%2 == 1){
            REP(i,K){
                ans = ans * vm[i] % mod;
            }
            ans = mod - ans;
            if(ans == mod) ans = 0;
        }
        else if(K % 2 == 0){
            REP(i,K){
                ans  = ans * vm[vm.size()-1-i] % mod;
            }
        }
        cout<<ans<<endl;
        return 0;
    }
    while(K > 0){
        if(plus.size() >= 2 && minus.size() >= 2){
            ll p1 = plus.top(); plus.pop();
            ll p2 = plus.top();
            ll m1 = minus.top();minus.pop();
            ll m2 = minus.top();
            if(p1 * p2 > m1 * m2){
                ll seki = p1*p2 % mod;
                ans = ans * seki % mod;
                plus.pop();
                minus.push(m1);
            }
            else{
                ll seki = m1*m2%mod;
                ans = ans*seki%mod;
                minus.pop();
                plus.push(p1);
            }
            
        }
        else if(plus.size()<2 && minus.size() >= 2){
            ll m1 = minus.top();minus.pop();
            ll m2 = minus.top();minus.pop();
            ll seki = m1*m2%mod;
            ans = ans*seki%mod;
        }
        else if(plus.size()>=2 && minus.size() < 2){
            ll p1 = plus.top(); plus.pop();
            ll p2 = plus.top(); plus.pop();
            ll seki = p1*p2 % mod;
            ans = ans * seki % mod;
        }

        K-=2;
    }

    /*if(K == 1){
        if()
    }*/

    cout << ans << endl;
}