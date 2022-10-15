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
    int N,M; cin >> N >> M;
    vector<int> H;
    vector<vector<int> > G(N);
    REP(i,N){
        int h; cin >> h; //h--;
        H.push_back(h);
    }
    REP(i,M){
        int a,b; cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int ans = 0;
    REP(i,N){
        if(G[i].size() == 0){
            //cout << i << endl;
            ans++;
        }
        else{
            bool flag = true;
            REP(k,G[i].size()){
                if(H[i] <= H[G[i][k]]){
                    flag = false; break;
                }
            }
            if(flag == true){
                //cout << i << endl;
                ans++;
            }
        }
    }

    cout << ans << endl;
}