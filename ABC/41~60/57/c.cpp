#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int gcd(int a,int b){
    int ma = max(a,b);
    int mi = min(a,b);
    if(ma % mi == 0){
        return mi;
    }
    else{
        return gcd(mi,ma%mi);
    }
 }

int main()
{
    int N;
    cin >> N;
    vector<int> vec;
    REP(i,sqrt(N)){
        if(N % i == 0){
            vec.push_back(i);
        }
    }
    int ans_N = N / vec[vec.size()-1];
    int ans = 0;
    while(ans_N / 10 == 0){
        ans_N = ans_N /10;
        ans++;
    }
    cout << ans << endl;
    return 0;
    
}