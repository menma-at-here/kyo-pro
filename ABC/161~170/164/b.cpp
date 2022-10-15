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
int A,B,C,D;
int main(){
    bool ans = true;
    cin >>A>>B>>C>>D;
    while(A>0 && C>0){
        C = C - B;
        if(C <= 0){
            break;
        }
        A = A - D;
        if(A <= 0){
            ans = false;
            break;
        }
    }
    cout << (ans ? "Yes":"No") << endl;
}