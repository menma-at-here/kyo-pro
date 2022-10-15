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
using vvi = vector<vector<int> >;
using vvll =  vector<vector<ll> >;

const ll inf = 1LL << 60;

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

int count2(ll a){
    int count = 0;
    while(a % 2 == 0){
        count++;
        a /= 2;
    }
    return count;
}
/*ll gcd(ll a, ll b){
    if(a < b)swap(a,b);
    while(a)
}*/

int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	//cout << fixed << setprecision(15);
    int N; ll M; cin >> N >>M;
    vector<ll> A(N);
    ll nowlcm = 1;
    int count;
    bool flag = false;
    REP(i,N){
        ll a; cin >> a;
        a /= 2;
        if(i == 0){
            count = count2(a);
        }
        else{
            int now = count2(a);
            if(count != now){
                flag = true;
                break;
            }
        }
        A[i] = a;
        //ll g = gcd(a,nowlcm);
        nowlcm = lcm(a,nowlcm);
        if(nowlcm > M){
            flag = true;
            break;
        }

    }
    if(flag){
        cout << 0 << endl;
        return 0;
    }

    //cout << nowlcm << endl;
    ll ans = ((M / nowlcm) + 1) / 2;
    cout << ans << endl;


}
