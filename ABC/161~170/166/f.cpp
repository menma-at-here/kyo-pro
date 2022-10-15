#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include<numeric>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	//cout << fixed << setprecision(15);
    int n,a,b,c; cin >> n>>a>>b>>c;
    vector<string> S(n);
    string alpha;
    REP(i,n){
        string s; cin>>s;
        S[i] = s;
    }
    if(a+b+c != 2){
    REP(i,n){
        if(S[i] == "AB"){
            if(a<b){
                a++;
                b--;
                alpha.push_back('A');
            }
            else{a--;b++;alpha.push_back('B');}
        }
        else if(S[i] == "BC"){
            if(b<c){b++; c--;alpha.push_back('B');}
            else{b--;c++;alpha.push_back('C');}
        }
        else if(S[i] == "AC"){
            if(a<c){a++;c--;alpha.push_back('A');}
            else{a--;c++;alpha.push_back('C');}
        }

        if(a<0 || b<0 || c<0){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    REP(i,n){
        cout << alpha[i] << endl;
    }
    }

    else{
        REP(i,n-1){
            if(S[i] == "AB"){
                if(a == 0){
                    a++; b--;
                    alpha.push_back('A');
                }
                else if (b == 0){
                    a--; b++;
                    alpha.push_back('B');
                }
                else if(a == 1 && b == 1){
                    if(S[i+1] == "BC"){
                        a--; b++;
                        alpha.push_back('B');
                    }
                    else{
                        a++; b--;
                        alpha.push_back('A');
                    }
                }
            }
            if(S[i] == "BC"){
                if(b == 0){
                    b++; c--;
                    alpha.push_back('B');
                }
                else if (c == 0){
                    b--; c++;
                    alpha.push_back('C');
                }
                else if(c == 1 && b == 1){
                    if(S[i+1] == "AB"){
                        c--; b++;
                        alpha.push_back('B');
                    }
                    else{
                        c++; b--;
                        alpha.push_back('C');
                    }
                }
            }
            if(S[i] == "AC"){
                if(a == 0){
                    a++; c--;
                    alpha.push_back('A');
                }
                else if (c == 0){
                    a--; c++;
                    alpha.push_back('C');
                }
                else if(a == 1 && c == 1){
                    if(S[i+1] == "BC"){
                        a--; c++;
                        alpha.push_back('C');
                    }
                    else{
                        a++; c--;
                        alpha.push_back('A');
                    }
                }
            }
            if(a < 0 || b < 0 || c < 0){
                cout << "No" << endl;
                return 0;
            }
        }

        if(S[n-1] == "AB"){
            if(a<b){
                a++;
                b--;
                alpha.push_back('A');
            }
            else{a--;b++;alpha.push_back('B');}
        }
        else if(S[n-1] == "BC"){
            if(b<c){b++; c--;alpha.push_back('B');}
            else{b--;c++;alpha.push_back('C');}
        }
        else if(S[n-1] == "AC"){
            if(a<c){a++;c--;alpha.push_back('A');}
            else{a--;c++;alpha.push_back('C');}
        }


        cout << "Yes" << endl;
        REP(i,n){
            cout << alpha[i] << endl;
        }
    }

}