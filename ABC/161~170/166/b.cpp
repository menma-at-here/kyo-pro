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

int N,K;

int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
    cin >> N >> K;
	//cout << fixed << setprecision(15);
    vector<bool> okashi(N);
    REP(i,N){
        okashi[i] = false;
    }

    //cin >> N >> K;
    REP(i,K){
        int d; cin >> d;
        REP(l,d){
            int a; cin >> a;
            okashi[a-1] = true;
        }
    }

    int ans = 0;
    REP(i,N){
        if(okashi[i] == false) ans++;
    }

    cout << ans << endl;
}