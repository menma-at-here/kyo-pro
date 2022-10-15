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
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> pll;
const ll inf = 1LL << 60;

int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	//cout << fixed << setprecision(15);
    int N,K,C; cin>>N>>K>>C;
    string S; cin>>S;
    vector<int> work;
    REP(i,N){
        if(S[i] == 'o'){
            work.push_back(i+1);
        }
    }
    vector<int> L(K), R(K); //(i)日目に働くのはL[i]日目以降(i =0スタート)
    int lnow = 0;
    int lnext = 1;
    L[0] = work[0];
    FOR(i,1,K){
        while(work[lnext] - work[lnow] <= C){
            lnext++;
        }
        L[i] = work[lnext];
        lnow = lnext;
        lnext++;
    }
    int rnow = work.size()-1;
    int rnext = work.size() -2;
    R[K-1] = work[work.size()-1];
    REPR(i,K-2){
        while(work[rnow] - work[rnext] <= C){
            rnext--;
        }
        R[i] = work[rnext];
        rnow = rnext;
        rnext--;
    }
    /*REP(i,K){
        cout<<L[i]<<" ";
    }
    cout<<endl;
    cout<<work.size()<<endl;
    REP(i,K){
        cout<<R[i]<<" ";
    }
    cout<<endl;*/
    vector<int> ans;
    REP(i,K){
        if(L[i] == R[i]) ans.push_back(L[i]);
    }
    if(ans.size() == 0){
        cout<<endl;
    }
    else{
        REP(i,ans.size()){
            cout<<ans[i]<<endl;
        }
    }
}