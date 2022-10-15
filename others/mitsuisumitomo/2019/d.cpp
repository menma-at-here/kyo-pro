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

    int n;
    string s;
    cin >>n;
    cin >>s;

    int ans = 0;
    bool flag[1000];
    REP(i,1000){
        flag[i] = false;
    }
    REP(i,10){
        REP(l,n-2){
            if(s[l]-'0' == i){
                REP(j,10){
                    FOR(p,l+1,n-1){
                        if(s[p] - '0' == j){
                            REP(k,10){
                                FOR(q,p+1,n){                        
                                    if(s[q]-'0' == k){
                                        int num = 100*i + 10*j + k;
                                        if(flag[num] == false){
                                            ans++;
                                            flag[num] = true;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    cout << ans << endl;
}