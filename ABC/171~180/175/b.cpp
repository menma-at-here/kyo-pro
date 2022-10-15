#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include<numeric>
#include<cmath>
#include<map>
#include<iomanip>
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
    int N; cin >> N;
    vector<int> L(N);
    REP(i,N){
        cin >> L[i];
    }
    int ans = 0;
    sort(ALL(L));
    /*REP(i,N){
        cout << L[i] << endl;
    }*/
    for(int i = 0;i < N - 2; i++){
        for(int j = i + 1; j < N - 1; j++){
            for(int k = j + 1; k < N; k++){
                if((L[i] != L[j] && L[j] != L[k]) && (L[i] + L[j] > L[k])){
                    ans++;
                    //cout << L[i] << " " << L[j] << " " << L[k] << endl;
                } 
            }
        }
    }
    cout << ans << endl;
}