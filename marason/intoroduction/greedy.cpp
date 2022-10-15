#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include<numeric>
#include<cmath>
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
const int numcon = 26;

const ll inf = 1LL << 60;
a
int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	//cout << fixed << setprecision(15);
    int D; cin>>D;
    vector<ll> C(numcon),last(numcon,0);
    vector<vector<ll> > S(D, vector<ll>(numcon));
    REP(i,numcon){
        cin>>C[i];
    }
    REP(i,D){
        REP(k,numcon){
            cin >> S[i][k];
        }
    }
    vector<ll> T(D);

    ll ans = 0;
    vector<ll> ansans(D);
    vector<ll> anscontest(D);

    REP(i,D){
        ll maxi = -inf;
        ll max_contest = -1;
        REP(k,numcon){ //どれが最大になるタイプか求める
            ll now = S[i][k];
            REP(j,numcon){  //タイプjのコンテスト分引く
                if(k != j){
                    now -= C[j] * (i+1 - last[j]);
                }
            }
            if(maxi < now){
                maxi = now;
                max_contest = k;  //k + 1番目のコンテストがその時点での最大値
            }
        }
        ans += S[i][max_contest];
        last[max_contest] = i+1;

        REP(k,numcon){
            ans -= C[k] * (i+1 - last[k]);
        }
        ansans[i] = ans;
        anscontest[i] = max_contest + 1;
    }

    REP(i,D){
        cout << anscontest[i] << endl;
    }
    
}