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
    int N; cin >>N;
    int a = N % 10;
    if (a ==2 || a == 4 || a == 5 || a == 7 || a == 9){
        cout << "hon" << endl;
    }
    else if(a == 3){
        cout << "bon" << endl;
    }
    else{
        cout << "pon" << endl;
    }

}