#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include<numeric>
#include<cmath>
#include<map>
#include<set>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> pll;
typedef vector<vector<int> > vvi;
typedef vector<vector<ll> > vll;
const ll inf = 1LL << 60;
const int numy = 2e5;

bool operator <(const P &a,const P &b){
    if(a.first == b.first) return a.second<b.second;
    return a.first < b.first;
}

int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	//cout << fixed << setprecision(15);
    int N,Q;cin>>N>>Q;
    //P ans(INF,INF);
    int ans = INF;
    //map<P,bool> mp[N];
    vector<int> where(N);
    vector<int> rate(N);
    vector<multiset<int> > st(numy);
    multiset<int> maxi;
    REP(i,N){
        int a,b; cin>>a>>b; b--;
        where[i] = b;
        rate[i] = a;
        st[b].insert(a);
        /*auto itr = st[b].rbegin();
        if(*itr < ans) ans = *itr;*/
        /*mp[b][P(a,i)] = true;
        if(*mp[b].rbegin().first  < ans.second) ans = P(b,*mp[b].rbegin().first);*/
    }

    REP(i,numy){
        if(!st[i].empty()){
            maxi.insert(*st[i].rbegin());
        }
    }

    vector<int> out(Q);
    REP(i,Q){
        int c,d; cin>>c>>d;
        c--, d--; //c: 幼稚園児の番号　d: 幼稚園の移転先

        int now_w = where[c];
        int max_prev = *st[now_w].rbegin();
        st[now_w].erase(st[now_w].find(rate[c]));
        if(st[now_w].empty()){
            maxi.erase(maxi.find(max_prev));
        }
        else{
            int max_next = *st[now_w].rbegin();
            if(max_prev > max_next){
                maxi.erase(maxi.find(max_prev));
                maxi.insert(max_next);
        }
        }
        
        if(st[d].empty()){
            st[d].insert(rate[c]);
            maxi.insert(rate[c]);
        }
        else{
            int maxi_prev = *st[d].rbegin();
            st[d].insert(rate[c]);
            int maxi_next = *st[d].rbegin();
            if(maxi_prev < maxi_next){
                maxi.erase(maxi.find(maxi_prev));
                maxi.insert(maxi_next);
            }
        }
         where[c] = d;

        out[i] = *maxi.begin();
        /*mp[now_w].erase(P(rate[c],c));
        if(mp[now_w].rbegin().first < ans.second) ans = P(now_w,*mp[now_w].rbegin().first);
        mp[d][P(rate[c],c)] = true;*/
    }

    REP(i,Q){
        cout << out[i] << endl;
    }
}