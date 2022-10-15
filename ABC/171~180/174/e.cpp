#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include<numeric>
#include<cmath>
#include<iomanip>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 1e9
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
using pll = pair<ll,ll>;
using vvii = vector<vector<int> >;
using vvll =  vector<vector<ll> >;

const ll inf = 1LL << 60;

//bool check()

int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(0);
    int N,K;cin>>N>>K;
    vector<int> A(N);
    REP(i,N){
        cin>>A[i];
    }

    int ng = 0, ok = INF+1;
    while(ok - ng > 1){
        int mid = (ng+ok)/2;
        int goukei = 0;
        REP(i,N){
            goukei += ((A[i]+mid-1)/mid)-1;
        }
        if(goukei <= K)ok = mid;
        else ng = mid;
    }
    cout << ceil(ok)<<endl;
}