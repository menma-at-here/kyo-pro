#include <iostream>
#include <string>
#include <vector>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int abc(string s,int itr){
    int flag = 0;
    if (s[itr] =='A' && s[itr+1] == 'B' && s[itr+2] == 'C'){
        flag = 1;
    }
    return flag;
}
int main()
{
    int N;
    string S;
    cin >> N >> S;

    int count = 0;
    REP(i, N-2){
        count += abc(S,i);
    }
    cout << count << endl;

    return 0;
}