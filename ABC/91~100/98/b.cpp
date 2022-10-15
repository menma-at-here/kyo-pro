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
int main(){
    int N;
    string S;
    cin >> N >> S;
    vector <int> alpha(26,0); 
    vector <int> beta(26,0);//アルファベット記憶
    int count = 0;
    int maxi = 0;
    REP(i,N){
        alpha[S.at(i) - 'a']++;
    }
    /*REP(i,alpha.size()){
        cout << alpha[i] << " ";
        cout << endl;
    }*/
    REP(i,N){
        alpha[S.at(i) - 'a']--;
        beta[S.at(i) -'a']++;
        if(alpha[S.at(i) - 'a'] == 0 && beta[S.at(i) -'a'] == 1){continue;}
        else if(alpha[S.at(i) - 'a'] == 0 && beta[S.at(i) -'a'] > 1){count--;}
        if(alpha[S.at(i) - 'a'] > 0 && beta[S.at(i) -'a'] == 1){count++;}
        else{continue;}
        maxi = max(maxi,count);
    }

    cout << maxi << endl;

    return 0;

}