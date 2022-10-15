#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
    int N,M;
    cin >> N >> M;
    vector<int> A(N);
    REP(i, N){
        cin >> A[i];
    }
    sort(ALL(A),greater<int>());

    int sum = accumulate(ALL(A),0);

    if(sum / (double)(4*M) <= A[M-1]){
        cout << "Yes" << endl;
    }

    else{
        cout << "No" << endl;
    }

    return 0;
}