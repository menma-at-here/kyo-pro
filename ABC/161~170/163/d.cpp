#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main(){
    ll N,K;
    cin >> N >> K;
    ll ans = 0;
    for(ll i = K; i <= N + 1; i++){
        ans += i * (N - i + 1) + 1;
        ans = ans % mod;
    }
    cout << ans << endl;
}