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
const int maxk = 10;

int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	//cout << fixed << setprecision(15);
    int n,m; cin >>n >> m;
    vector<vector<int> > light;
    REP(i,m){
        int k; cin >> k;
        vector<int> ss;
        light.push_back(ss);
        REP(l,k){
            int s; cin >> s; s--;
            light[i].push_back(s);
        }
    }
    vector<int> p; 
    REP(i,m){
        int pp; cin >> pp;
        p.push_back(pp);
    }
    int ans = 0;
    for(int bit = 0; bit < (1<<n); bit++){
        bool flag = true;
        REP(i,m){
            int on = 0;
            REP(k,n){
                if(bit & (1<<k)){
                    if(binary_search(ALL(light[i]), k)){
                        on++;
                    }
                }
            }
            if (on % 2 != p[i]) {
                flag = false; 
                break;
            }

        }
        if(flag) ans++;
    }

    cout << ans << endl;
}