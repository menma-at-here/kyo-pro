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

int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	//cout << fixed << setprecision(15);
    int K; cin>>K;
    string S; cin>> S;
    if(S.size() <= K){
        cout << S << endl;
    }
    else{
        string sub = S.substr(0,K);
        REP(i,3){
            sub.push_back('.');
        }
        cout << sub << endl;
    }
    //endl;
}