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
typedef vector<vector<int> > vvi;
typedef vector<vector<ll> > vll;
const ll inf = 1LL << 60;

int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	//cout << fixed << setprecision(15);
    int N,K;cin>>N>>K;
    int A[N];
    REP(i,N){
        cin>> A[i];
    }
    int maxi=min(K,150);
    REP(i,maxi){
        vector<int> imos(N,0);
        REP(i,N){
            if(i-A[i] < 0) imos[0]++;
            else imos[i - A[i]]++;

            if(i+A[i]+1>N-1) continue;
            else imos[i+A[i]+1]--;
        }
        A[0] = imos[0];
        REP(i,N-1){
            A[i+1] = A[i] + imos[i+1];
        }
    }

    REP(i,N){
        cout<<A[i] << endl;
    }
}