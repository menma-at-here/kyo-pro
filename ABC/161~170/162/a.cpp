#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main(){
    int N;
    cin >> N;
    bool flag = false;
    while(N != 0){       
        if(N % 10 == 7){flag = true;break;}
        else{
            N = N / 10;
        }

    }
    cout << (flag ? "Yes" : "No") << endl;
}