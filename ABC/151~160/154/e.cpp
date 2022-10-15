#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include<numeric>
#include<cmath>
#include<map>
#include<iomanip>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
using pll = pair<ll,ll>;
using vvii = vector<vector<int> >;
using vvll =  vector<vector<ll> >;

const ll inf = 1LL << 60;

int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	//cout << fixed << setprecision(15);

    string number;
    cin >> number;
    //cout << number << endl;
    int K; cin >> K;
    vector<vector<int> > smaller(number.length()+1,vector<int>(K+1,0)), equal(number.length()+1,vector<int>(K+1,0));
    equal[0][0] = 1;
    //smaller[0][0] = 1;
    REP(i,number.length()){
        REP(j,K+1){
            if(number[i] == '0'){
                equal[i+1][j] = equal[i][j];
            }
            else{
                if(j >= 1) equal[i+1][j] = equal[i][j-1];
                else equal[i+1][0] = 0;
            }
        }
    }

    REP(i,number.length()){
        REP(j,K+1){
            if(number[i] == '0'){
                if(j >= 1) {
                    smaller[i+1][j] = (smaller[i][j] + smaller[i][j-1] * 9);
                }//i桁目が0になる数字を足す
                else{
                    smaller[i+1][j] = smaller[i][j];
                }
                
            }
            else{
                if(j >= 1){
                    smaller[i+1][j] = equal[i][j] + equal[i][j-1] * (number[i] - '0'-1) + smaller[i][j] + smaller[i][j-1] * 9;
                }
                else{
                    smaller[i+1][j] = equal[i][j] + smaller[i][j];
                }
            }
        }
    }

    /*REP(i,number.length()+1){
        REP(j,K+1){
            cout << smaller[i][j] << " ";
        }
        cout << endl;
    }*/

    int ans =smaller[number.length()][K] + equal[number.length()][K];
    
    cout << ans << endl;

}