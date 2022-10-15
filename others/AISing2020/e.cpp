#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include<numeric>
#include<cmath>
#include<queue>
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
struct camel{
    ll left;
    ll right;
    ll diff;
    ll K;
    camel(ll l, ll r, ll d, ll k){
        left =l,right=r,diff=d,K=k;
    }
    /*bool operator< (const camel& dst)const{
        if(diff)
    };*/
};

bool comp(const camel& a, const camel& b){
    if(a.diff == b.diff){
        if(a.K == b.K){
            if(a.left == b.left){
                return a.right < b.right;
            }
            return a.left < b.left;
        }
        return a.K < b.K;
    }
    return a.diff < b.diff;
}



int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	//cout << fixed << setprecision(15);

    auto comp_pair_second = [](pll p1, pll p2){
        return p1.second > p2.second;  //昇順
    };

    int T; cin>>T;
    vector<ll> vec(T);
    REP(_,T){
        ll ans = 0;
        int N;cin>>N;
        vector<pll> LL,RR;  //LL には L > R のやつのdiffを入れる
        priority_queue <pll, vector<pll>, decltype(comp_pair_second)> frL(comp_pair_second);
        priority_queue <pll, vector<pll>, decltype(comp_pair_second)> frR(comp_pair_second);
        REP(i,N){
            ll k,l,r; cin >> k >> l >> r;
            if(l > r){
                ans += r;
                LL.push_back(pll(k-1,l-r));
            }
            else{
                ans += l;
                RR.push_back(pll(N - k - 1,r-l));  //ここ大事
            }
        }
        sort(ALL(LL));
        sort(ALL(RR));

        int itrl = 0;
        if(LL.size() >= 1){
            REP(i,N){            
                while(itrl < LL.size() && LL[itrl].first < i){
                    itrl++;
                    if(itrl >= LL.size())break;
                }
                while(itrl < LL.size() && LL[itrl].first == i){
                    frL.push(LL[itrl]);
                    itrl++;
                    if(itrl >= LL.size())break;
                }
                while(frL.size() > i + 1){
                    frL.pop(); 
                }
            }
            while(!frL.empty()){
                ans += frL.top().second;
                //cout << "N:" << N << " " << frL.top().second << endl;
                frL.pop();
            }
        }
        

        int itrr = 0;
        for (int i = 0; i < N; i++){
            if(RR.size() == 0)break;
            while(RR[itrr].first < i && itrr < RR.size()){
                itrr++;
                if(itrr >= RR.size())break;
                }
            while(itrr < RR.size() && RR[itrr].first == i){
                frR.push(RR[itrr]);
                itrr++;
                if(itrr >= RR.size())break;
            }
            while(frR.size() > i + 1){
                frR.pop();
            }

            if(itrr >= RR.size())break;
        } //このかっこの中に問題がある
        while(!frR.empty()){
                ans += frR.top().second;
                frR.pop();
        }

        vec[_] = ans;

    }

    REP(i,T){
        cout << vec[i] << endl;
    }
}