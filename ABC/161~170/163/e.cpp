#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define REP(i, n) for(ll i = 0; i < n; i++)
#define REPR(i, n) for(ll i = n; i >= 0; i--)
#define FOR(i, m, n) for(ll i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

ll N;
typedef struct infant{
    ll liveliness;
    ll oldplace;
    ll newplace;
    ll rank;
}Infant;
vector<Infant> vec;

bool comp(Infant a,Infant b){
    return(a.liveliness > b.liveliness);
}

int main(){
    cin >> N;
    REP(i,N){
        ll k;
        cin >> k;
        Infant I;
        I.liveliness = k;
        I.oldplace = i;
        vec.push_back(I);
    }

    sort(ALL(vec),comp);
    /*REP(i,N){
        cout << vec[i].liveliness << " ";
    }
    cout << endl;*/
    ll dp[N+1][N+1];
    bool breaker = false;
    REP(i,N+1){
        REP(j,N+1){
            dp[i][j] = 0;
        }
    }

    REP(i,N+1){
        REP(j,N+1){
            if(i + j > N){continue;}
            else{
                if(j == 0 && i != 0){
                    dp[i][0] = dp[i-1][0] + vec[i-1].liveliness * abs(N-i-vec[i-1].oldplace);
                    //cout << "dp[i][0]" << dp[i][0] << endl;;
                }
                else if(j != 0 && i == 0){
                    dp[0][j] = dp[0][j-1] + vec[j-1].liveliness * abs(vec[j-1].oldplace - j + 1);
                    //cout << "dp[0][j]" << dp[0][j] <<endl;
                }
                else if(j != 0 && i != 0){
                    ll iii = dp[i-1][j] + vec[i+j-1].liveliness * abs(N-i-vec[i+j-1].oldplace);
                    ll jjj = dp[i][j-1] + vec[i+j-1].liveliness * abs(vec[i+j-1].oldplace-j+1);
                    dp[i][j] = max(iii,jjj);
                }
            }
        }
    }

    ll maxi = 0;
    /*REPR(i,N){
        if(maxi <= dp[i][N-i]){
            maxi = dp[i][N-i];
            cout << dp[i][N-i] << " " << i << endl;
        }
        
    }*/
    REP(i,N+1){
        maxi = max(maxi,dp[i][N-i]);
    }
    cout << maxi << endl;
}