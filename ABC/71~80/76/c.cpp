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

string S,T;

bool check_string(string subs, string T){
    bool flag = true;
    REP(i,subs.length()){
        if(subs[i] != T[i] && subs[i] != '?'){
            flag = false;
            break;
        }
    }
    return flag;
}


int main(){
    cin >> S;
    cin >> T;
    int sizes = S.length();
    int sizet = T.length();
    vector<string> str;
    int part = sizes - sizet + 1;
    bool flag = false;
    if(part <= 0) {cout << "UNRESTORABLE" << endl;return 0;}
    else{
        REP(i,part){
            string SS;
            //SS = S;
            string subs = S.substr(i,sizet);
            if(check_string(subs,T)){
                flag = true;
                REP(k,sizes){
                    if(k < i || k >= i + sizet){
                        if(S[k] == '?'){
                            SS.append("a");
                        }
                        else{
                            SS.append(S.substr(k,1));
                        }
                    }
                    else{
                        SS.append(T.substr(k-i,1));
                    }
                    
                }
                str.push_back(SS);
            }
        }
    }
    sort(ALL(str));

    cout << (flag ? str[0] : "UNRESTORABLE") << endl;
    return 0;
}