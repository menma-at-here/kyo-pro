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
    int N,K;cin >>N>>K;
    vector<int> P(N);
    REP(i,N){
        cin >> P[i];
        P[i]--;
    }
    vector<ll> C(N);
    REP(i,N)cin >> C[i];

    vector<bool> seen(N,false);
    vector<int> count(N,0);
    vector<ll> sum(N,0);
    REP(i,N){
        if(seen[i] == false){
            int now = 0;
            int where = i;
            ll now_sum = 0;
            while(true){
                if(seen[where])break;
                now++;
                now_sum += C[where];
                seen[where] = true;
                where = P[where];
            }
            while(true){
                count[where] = now;
                sum[where] = now_sum;
                where = P[where];
                if(where == i)break;
            }
            //cout << count[i] << " " << sum[i] << endl;

        }
        
    }
    ll ans = -inf;
    //vector<bool> ok(N,false);
    REP(i,N){
        ll shou = K / count[i];
        ll amari = K % count[i];
        ll ruiseki = 0;
        ll now_maxi = -inf;
        int now = i;
        
        REP(k,amari + count[i]){
            ruiseki += C[now];
            now_maxi = max(now_maxi,ruiseki);
            now = P[now];    
        }
        if(sum[i] > 0){
            ans = max(ans, (shou-1)*sum[i] + now_maxi);
        }
        else{
            ans = max(ans, now_maxi);
        }
        /*REP(j,amari){
            ruiseki += C[now];
            now = P[now];
        }
        int front = now;
        int back = i;
        int maxi = ruiseki;

        REP(j,count[i]){
            ll next = ruiseki; //次の累積和
            next -= C[back];
            next += C[front+1];
            ok[back] = true;
            maxi = max(ruiseki,next);

            front = P[front];
            back = P[back];
            ruiseki = next;
        }*/

        //ans = max(ans,shou * sum[i] + maxi);
    
    }

    cout << ans << endl;
}