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
    int n,m,x; cin >>n>>m>>x;
    vector<int> C(n);
    int A[n][m];
    REP(i,n){
        cin>>C[i];
        REP(k,m){
            cin >> A[i][k];
        }
    }
    bool flag = false;
    int ans = INF;
    for(int bit = 0; bit < (1<<n); bit++){
        int money = 0;
        vector<int> rikai(m,0);
        REP(i,n){
            if(bit & (1<<i)){
                money += C[i];
                REP(k,m){
                    rikai[k] += A[i][k];
                }
            }
        }
        bool flag_rikai = true;
        REP(i,m){
            if(rikai[i] < x){
                flag_rikai = false; break;
            }
        }

        if(flag_rikai){
            flag = true;
            ans = min(ans,money);
        }
    }
    cout << (flag ? ans : -1) << endl;
}