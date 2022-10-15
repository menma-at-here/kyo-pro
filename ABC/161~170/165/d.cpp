#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include<numeric>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	//cout << fixed << setprecision(15);
    ll a,b,n;
    cin >> a>>b>>n;

    ll alpha,ganma;
    alpha = a / b;
    ganma = a % b;
    ll ans = 0;
    if(b != 1){
        if(a <= b){
            if(n >= b){
                ans = a - 1;
            }
            else{
                ans = a * n / b;
            }
        }
        else{
        
        
                if(n>=b){
                    ans = alpha*(b-1) + ganma-1;
                }
                else{
                    ans = alpha*n + ganma*n / b;
                }
            
        }
        cout << ans << endl;
        }

    else{
        cout << 0 << endl;
    }
}