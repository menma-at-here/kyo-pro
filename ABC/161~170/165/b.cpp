#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include<numeric>
#include <cmath>
#define REP(i, n) for(ll i = 0; i < n; i++)
#define REPR(i, n) for(ll i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
//#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const ll INF = 1LL << 63;

int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	//cout << fixed << setprecision(15);
    ll x; cin >> x;
    ll a = 100;
    int itr = 0;
    //cout << a * 1.01<<endl;
    REP(i,4000){
        a = a * 1.01;
        if(x <= a){
            cout << i+1 << endl;
            break;
        }
    } 
    //cout << a * 1.01<<endl;
    
}