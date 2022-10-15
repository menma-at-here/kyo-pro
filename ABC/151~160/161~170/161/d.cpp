#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
    ll K;
    cin >> K;
    vector<ll> lun(100000,0);
    REP(i,10){
        lun[i] = i;
    }
    ll dig = 2;
    ll lunlun; //桁数
    vector<int> serve(10,0);
    serve[0] = 1;
    int index = 10;
    while(lun[K] == 0){
        if(lunlun == pow(10,dig) - 1){
            lun[index] = lunlun;
            lunlun++;
            serve[0] = 1;
            for(int i= 1; i < dig; i++){
                serve[i] = 0;
            }
            dig++;
        }
        else{
            for(int i=1; i <dig;i++){
                if(serve[dig-i-1] == serve[dig-i] - 1){
                    if(i == dig - 1){
                        serve[0]++;
                        
                    }
                }
            }
        }
    }

}