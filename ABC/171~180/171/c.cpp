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
const ll m = 26;

const ll inf = 1LL << 60;

int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	//cout << fixed << setprecision(15);
    ll N; cin>>N;
    ll minus = m;
    ll count = 0;
    ll now = N;
    string ans;
    //N;
    while(now != 0){
        ll amari =  (now - 1) % minus;
        ans += amari + 'a';
        now -= (amari + 1);
        now /= m;
    }
    reverse(ALL(ans));
    cout<< ans<<endl;
    /*ll now = N;
    ll minus = m;
    ll count = 0;
    while(true){
        if(N - minus < 0)break;
        minus *= m;
        count++;
    }
    vector<char> ans;
    minus /= m;
    ll n = N;
    REP(i,count-1){
        char c = N / minus + 'a'-1;
        N %= minus;
        //cout << N  << " " << c << endl;
        minus /= m;
        ans.push_back(c);
    }
    ans.push_back(N  + 'a');
    REP(i,ans.size()){
        cout<<ans[i];
    }
    cout << endl;*/
}