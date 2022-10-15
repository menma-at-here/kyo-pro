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
const ll mod = 1e9 + 7;

const ll inf = 1LL << 60;

int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	//cout << fixed << setprecision(15);
    ll D; cin>>D;
    vector<ll> C(numcon);
    vector<vector<ll> > S(D, vector<ll>(numcon)),last(numcon,vector<ll>(1,0));
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
                    now -= C[j] * (i+1 - *last[j].rbegin());
                }
            }
            if(maxi < now){
                maxi = now;
                max_contest = k;  //k + 1番目のコンテストがその時点での最大値
            }
        }
        ans += S[i][max_contest];
        last[max_contest].push_back(i+1);

        REP(k,numcon){
            ans -= C[k] * (i+1 - *last[k].rbegin());
        }
        ansans[i] = ans;
        anscontest[i] = max_contest + 1;
    }

    ll count = 0;
    while(count <= 3e4){
        ll day = (count*mod + 50) % D; //更新する日にち
        ll contest = (count* mod + 6) % numcon; //新しいコンテスト
        ll old = anscontest[day] - 1; //古いコンテスト

        ll now = 0;
        now += (S[day][contest] - S[day][old]);
        ll minus = 0;
        auto itrold = lower_bound(ALL(last[old]), day);
        if(last[old].size() == 1){
            minus = (D - old) * old * C[old];
        }
        else{
            if(*itrold == *last[old].rbegin()){
                minus = C[old] * (*(last[old].rbegin()) - *(last[old].rbegin()-1) ) * (D - day);
            }
            else if(*lower_bound(ALL(last[old]), day) == *last[old].begin()){
                minus = C[old] * (*(last[old].begin() + 1) - *(last[old].begin())) * (day);
            }
            else{
                minus = C[old] * (*(itrold + 1) - *itrold) * (*itrold - *(itrold - 1));
            }
        }
        

        ll plus;
        auto itrnew = lower_bound(ALL(last[contest]), day);
        if(last[contest].size() == 0){
            plus = C[contest] * day * (D - day);
        }
        else if(last[contest].size() == 1){
            if(*itrnew == *last[contest].rbegin()){
                plus = C[contest] * day * (*itrnew-day);
            }
            else{
                plus = C[contest] * (day - *last[contest].begin()) * (D - day);
            }
        }
        else{
            if(itrnew == last[contest].end()){
                minus = C[contest] * (day - *last[contest].rbegin() ) * (D - day);
            }
            else if(itrnew == last[contest].begin()){
                minus = C[contest] * (*last[contest].begin() - day) * (day);
            }
            else{
                minus = C[contest] * (*itrnew - day) * (day - *(itrnew - 1)) ;
            }
        }
        

        if(now + plus - minus > 0){
            anscontest[day] = contest + 1;
            last[old].erase(itrold);
            last[contest].insert(itrnew, day);

        }
        count++;
    }
    


    REP(i,D){
        cout << anscontest[i] << endl;
    }
    
}