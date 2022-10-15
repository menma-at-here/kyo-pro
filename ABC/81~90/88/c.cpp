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
    int C[3][3];
    REP(i,3){
        REP(k,3){
            cin >> C[i][k];
        }
    }
    vector <int> a(3,0), b(3,0);
    //if(C[0][0] == 0) a[0] = 0, b[0] = 0;
    REP(i,C[0][0]+1){
        a[0] = i , b[0] = C[0][0] - i;
        b[1] = C[0][1] - a[0];
        b[2] = C[0][2] - a[0];
        a[1] = C[1][0] - b[0];
        a[2] = C[2][0] - b[0];
        bool flag = true;
        for(int k = 1; k<= 2; k++){
            for(int j = 1; j <= 2; j++){
                if(a[k] + b[j] != C[k][j]) flag = false;
            }
        }
        if(flag){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}