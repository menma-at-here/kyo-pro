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
using pdd = pair<double,double>;
using vvi = vector<vector<int> >;
using vvll =  vector<vector<ll> >;

int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(15);
    ll N,X,M;cin>>N>>X>>M;
    vector<int> seen(M+1,-1);
    ll ans = 0;
    //ans += X;
    //X %= M;    
    ll now = X % M;
    //ans += X - now;
    int count = 1;
    int start;
    int period;
    ll sum_period = 0;
    while(true){
        now *= now;
        now %= M;
        if(seen[now] == -1){
            seen[now] = count;
            count++;
        }
        else{
            period = count - seen[now];
            start = now;
            break;
        }
    }

    //cout << period << " "<<start << endl;
    ll where = start;

    REP(i,period){
        sum_period += where;
        where = where * where % M;
    }

    //cout << sum_period << endl;
    now = X;
    REP(i,seen[start]){
        ans += now;
        now = now * now % M;
        //cout <<"1" << endl;
    }
    REP(i,(N - seen[start]) / period){
        ans += sum_period;
        //cout << "2" << endl;
    }

    ll nowend = start;
    for(ll i = seen[start] + ((N - seen[start]) / period) * period; i < N; i++){
        ans += nowend;
        nowend = nowend*nowend % M;
        //cout << "3" << endl;
    }

    cout << ans << endl;


}

