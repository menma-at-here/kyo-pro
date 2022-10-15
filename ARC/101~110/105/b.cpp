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

int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(15);
    int N; cin >> N;
    vector<int> A(N);
    int mini = INF;
    int max = 0;
    int gcd_all;
    REP(i,N){
        cin >> A[i];
        mini = min(mini,A[i]);
        if(i == 0){
            gcd_all = A[i];
        }
        else{
            gcd_all = gcd(gcd_all,A[i]);
        }
    }

    cout << gcd_all << endl;
}

