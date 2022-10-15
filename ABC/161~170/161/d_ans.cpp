#include <iostream>
#include <string>
#include <vector>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main(){
    int k;
    cin >> k;
    vector <ll> a;
    for(int i = 1; i < 10; i++){a.push_back(i);}
    while(1){ //このループ中に桁を一つ増やす
        if(k <= a.size()){
            cout << a[k-1] << endl;
            return 0;
        }
        k -= a.size();
        vector<ll> old;
        swap(old,a); //oldは桁数が一つ少ない配列
        for(ll x: old){
            for(int i = -1; i <= 1; i++){
                int d = x % 10 + i;
                if(d < 0 || d > 9){continue;}
                ll nx = x * 10 + d;
                a.push_back(nx);
            }
        }

    }
}
