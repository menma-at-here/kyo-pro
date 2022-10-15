#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define REP(i, n) for(ll i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main(){
    ll N;
    cin >> N;
    ll sum = 0;
    REP(i,N + 1){
        if(i %3 != 0 && i % 5 != 0 ){
            sum += i;
        }
    }
    cout << sum << endl;
}