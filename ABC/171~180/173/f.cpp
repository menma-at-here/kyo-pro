#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include<numeric>
#include<cmath>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
using pll = pair<ll,ll>;
using vvii = vector<vector<int> >;
using vvll =  vector<vector<ll> >;

const ll inf = 1LL << 60;

int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	//cout << fixed << setprecision(15);
    int N; cin>>N;
    vvii G(N);
    REP(i,N-1){
        int u,v; cin>>u>>v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    REP(i,N){
        sort(ALL(G[i]));    
    }
    vector<ll> size(N,0);
    ll ans = 0;
    ll kosuu = 0;
    //ll plus = 0;
    REP(i,N){
        ll plus = 1 - (lower_bound(ALL(G[i]), i) - G[i].begin());
        kosuu += plus;
        ans += kosuu;
    }
    //cout << ans << endl;
    size[0] = ans;
    REP(i,N-1){
        int plus = 0;
        if(lower_bound(ALL(G[i]), i) == G[i].end()){
            plus = i - N;
        }
        else{
            plus = -(*lower_bound(ALL(G[i]),i) - i);
            //cout<<plus<<endl;
            int itr = lower_bound(ALL(G[i]),i) - G[i].begin();
            REP(k,G[i].size()-itr-1){
                plus += k * (G[i][k+itr+1] - G[i][k+itr]);
            }
            plus += (G[i].size()- itr- 1) * (N - G[i][G[i].size() - 1]);
        }
        //cout << i << " "<< plus<<endl;
        size[i+1] = size[i] + plus;
        ans += size[i+1];
    }

    cout << ans << endl;
}