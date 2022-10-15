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
    int A,B,K;
    cin >> A >> B >> K;
    int C = gcd(A,B);
    int itr = 0;
    vector <int> vec; //約数を列挙
    for(int i = 1; i <= sqrt(C); i++){
        if(C % i == 0){
            vec.push_back(i);
            itr++;
        }
    }
    REPR(i,itr-1){
        vec.push_back(C / vec[i]);
    }
    if(vec[itr-1] == vec[itr]){vec.erase(vec.begin() + itr);}

    /*REP(i,vec.size()){
        cout << vec[i] << endl;
    }*/

    cout << vec[vec.size() - K] << endl;
}