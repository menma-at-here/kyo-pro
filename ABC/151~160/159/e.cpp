#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include<numeric>
#include<cmath>
#include<bitset>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> pll;
const ll inf = 1LL << 60;

int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	//cout << fixed << setprecision(15);
    int H,W,K;
    cin>>H>>W>>K;
    int SS[H][W];
    //cout << 0  << endl;
    REP(i,H){
        REP(j,W){
            char c; cin>>c;
            if(c == '0')SS[i][j] = 0;
            else SS[i][j] = 1;
        }
    }
    //cout << 0 << endl;
    //int ans = INF;
    int mini = INF;
    //if(H >= 2){
        for(int S = 0 ; S < (1<<(H-1)); S++){
            int ans = bitset<32>(S).count();
            //cout <<ans<<endl;
            vector<int> choco(ans+1,0);
            vector<P> divide;
            int start = 0;
            //int end = 0;
            REP(i,H-1){
                if(S & (1<<i)){
                    divide.push_back(P(start,i+1));
                    start = i+1;
                }
            }
            divide.push_back(P(start,H));
            bool flag =true; //そもそもありえるかのflag
            int itr = 0; //これはなに
            REP(i,W){
                bool f = true;
                REP(k,divide.size()){
                    int new_choco = 0;
                    for(int j = divide[k].first; j < divide[k].second; j++){
                        if(SS[j][i] == 1) new_choco++;
                    }
                    choco[k] += new_choco;
                    if(choco[k] > K){
                        f = false; break;
                    }
                }
                if(!f){
                    if(itr == 0){
                        flag = false; break;
                    }
                    else{
                        //if(S ==0) cout << itr<<endl;
                        itr = 0; ans++;
                        REP(k,divide.size()){
                            choco[k] = 0;
                        }
                        /*REP(k,divide.size()){
                            int new_choco = 0;
                            for(int j = divide[k].first; j < divide[k].second; j++){
                                if(SS[i][j] == 1) new_choco++;
                            }
                            choco[k] = new_choco;
                        }*/
                        i--;
                    }
                }
                else{
                    itr++;
                }
            }
            //cout << S << ans<<endl;
            if(!flag) continue;
            else mini = min(ans,mini);
        }
    //}
    cout << mini << endl;
}