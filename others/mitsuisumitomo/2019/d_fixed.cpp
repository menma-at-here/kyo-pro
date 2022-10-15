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

    int n;
    string s;
    cin >>n;
    cin >>s;
    vector<vector<int> > num(10);

    REP(i,n){
        int m = s[i] - '0';
        num[m].push_back(i);
    }
    /*REP(i,num[1].size()){
        cout << num[1][i] << endl;
    }
    int ans = 0;
    bool flag[1000];
    REP(i,1000){
        flag[i] = false;
    }

    REP(i,10){
        REP(j,10){
            REP(k,10){
                if(num[i].size() != 0){
                    int ii = num[i][0];
                    if(num[j].size() != 0){
                        if(num[j][num[j].size()-1] > ii){
                            auto itrj = upper_bound(ALL(num[j]), ii);
                            int jj = *itrj;
                            if(num[k].size() != 0 && num[k][num[k].size()-1] > jj){
                                if(flag[100*i+10*j+k] == false){
                                    //cout << i<<j<<k << endl;
                                    ans++;
                                    flag[100*i+10*j+k] = true;
                                }
                            }
                        }    
                    }
                } 
            }
        }
    }

    cout << ans << endl;

}