#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 5e16
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main(){
    ll N;
    cin >> N;
    vector<ll> a;
    REP(i,3*N){
        ll b;
        cin >> b;
        a.push_back(b);
    }
    priority_queue<ll> right;
    priority_queue<ll,vector<ll>,greater<ll> > left;
    ll dpleft[N+1], dpright[N+1];
    dpleft[0] = 0;
    dpright[0] = 0;
    REP(i,N){
        left.push(a[i]);
        right.push(a[3 * N - 1 - i]);
        dpleft[0] += a[i];
        dpright[0] += a[3*N-1-i];
    }
    
    REP(i,N){
        if(a[N+i] > left.top()){
            dpleft[i+1] = dpleft[i] - left.top() + a[N+i];  //left.topは一番小さいやつ
            left.pop();
            left.push(a[N+i]);
        }
        else{
            dpleft[i+1] = dpleft[i];
        }   
    }
    REP(i,N){
        if(a[2*N-1-i] < right.top()){
            dpright[i+1] = dpright[i] - right.top() + a[2*N-1-i];
            right.pop();
            right.push(a[2*N-1-i]);
        }
        else{
            dpright[i+1] = dpright[i];
        }
    }
    ll ans = -INF;
    REP(i,N+1){
        ans = max(ans,dpleft[i] - dpright[N-i]);
    }
    cout << ans << endl;

}
