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

int N;
vector<int> A;
int main(){
    cin >> N;
    REP(i,N-1){
        int a;
        cin >> a;
        A.push_back(a);
    }
    int buka[N];
    REP(i,N){
        buka[i] = 0;
    }
    REP(i,N-1){
        buka[A[i] - 1]++;
    }
    REP(i,N){
        cout << buka[i] << endl;
    }

}