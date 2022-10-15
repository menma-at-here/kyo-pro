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

int  A,B;
vector<int> avalue, bvalue;

bool sente(int A,int B,int i,int j){
    if((A + B) % 2 == 0){
        if((A + B - i - j) % 2 == 0) return true;
        else return false;
    }
    else{
        if((A + B - i - j) % 2 == 0) return true;
        else return false;
    }
}
int main(){
cin >> A >> B;
REP(i,A){
    int a;
    cin >> a;
    avalue.push_back(a);
}
REP(i,B){
    int b;
    cin >> b;
    bvalue.push_back(b);
}

int dp[A+1][B+1];
dp[0][0] = 0; 
REP(i,A+1){
    REP(j,B+1){
        if (sente(A,B,i,j)){
            if(i == 0 && j == 0){continue;}
            else if(i == 0 && j != 0){dp[0][j] = dp[0][j-1] + bvalue[B-j];}
            else if(j == 0 && i != 0){dp[i][0] = dp[i-1][0] + avalue[A-i];}
            else{dp[i][j] = max(dp[i][j-1] + bvalue[B-j], dp[i-1][j] + avalue[A-i]);}
        }
        else{
            if(i == 0 && j == 0){continue;}
             else if(i == 0 && j != 0){dp[0][j] = dp[0][j-1];}
             else if(j == 0 && i != 0){dp[i][0] = dp[i-1][0];}
             else{dp[i][j] = min(dp[i][j-1], dp[i-1][j]);}
        }
    }
}
    cout << dp[A][B] << endl;

}