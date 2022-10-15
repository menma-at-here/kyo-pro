#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
const int Max_n = 200000;

int N;
typedef pair<string, int> P;
map<string, int> kuji;

int main(){
    cin >> N;
    REP(i,N){
        string s;
        cin >> s;
        
        kuji.insert(P(s,0));
    }
    cout << kuji.size() << endl;
}