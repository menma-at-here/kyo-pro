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
    int N,M; cin>>N>>M;
    string S; cin>>S;
    //reverse(ALL(S));
    vector<int> ans;
    int now = N;
    bool flag = true;
    while(now > 0){
        int count = min(M,now);
        while(S[now - count] == '1'){
            count--;
            if(count == 0){
                flag = false;
                break;
            }
        }
        if(!flag)break;
        ans.push_back(count);
        now -= count;
        //cout << now <<" " << count<< endl;
    }
    if(!flag){
        cout << -1 << endl;
        return 0;
    }
    for(int i = ans.size()-1; i>0; i--){
        cout << ans[i]<< " ";
    }
    cout << ans[0]<<endl;

}