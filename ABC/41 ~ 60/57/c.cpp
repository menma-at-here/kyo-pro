#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#define REP(i, n) for(int i = 1; i < n; i++)
#define REPR(i, n) for(int i = n; i > 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int getdig(ll N){
    int digit = 0;
    while(N != 0){
        N /= 10;
        digit++;
    }
    return digit;
}

int main()
{
    ll N;
    cin >> N;
    /*vector<ll> vec;
    REP(i,sqrt(N)){
        if(N % i == 0){
            vec.push_back(i);
        }
    }
    ll ans_N = N / vec[vec.size()-1];
    ll ans = 0;
    while(ans_N != 0){
        ans_N = ans_N / 10;
        ans++;
    }
    cout << ans << endl;
    return 0;*/
    ll ansN = 1;
    REPR(i,ceil(sqrt(N))){
        if(N % i == 0){
            ansN = i;
            break;
        }
        else{continue;}
    }
    ll ans_N = N / ansN;
    cout << getdig(ans_N)<< endl;

    return 0;
    
}

