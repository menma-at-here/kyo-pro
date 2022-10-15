#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include<numeric>
#include<cmath>
#include<map>
#include<iomanip>
#include<set>
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
const ll inf = 1LL<<60;

int main(){
    //cin.tie(nullptr);
	//ios_base::sync_with_stdio(false);
	//cout << fixed << setprecision(15);
    int N,M; cin>>N>>M;
    vector<ll> W(N);

    REP(i,N){
        cin >> W[i];
    }
    sort(ALL(W));
    vector<ll> L(M),V(M);
    REP(i,M){
        cin>>L[i]>>V[i];
    }

    ll ans = 0;
    bool flag = true;
    REP(i,M){
        int group = 0;
        multiset<ll> wnow;
        REP(k,N){
            wnow.insert(W[k]);
        }
        if(W[N-1] > V[i]){
            flag = false;
            break;
        }

        while(true){

            auto itr = wnow.begin();
            ll small = *itr;
            wnow.erase(itr);
            auto itr2 = wnow.upper_bound(V[i] - small);
            if(itr2 == wnow.begin()){
                ans = max(ans,L[i]*( (ll)wnow.size() ) );
                if( (L[i] * (ll)wnow.size()) == 3756){
                    for(auto itr3 = wnow.begin(); itr3 != wnow.end(); itr3++){
                        cout << *itr3 << endl;
                    }
                    cout << L[i] << endl;
                }
                break;
            }
            else{
                small += *prev(itr2);
                wnow.erase(prev(itr2));
                wnow.insert(small);
            }

        }
    }

    cout <<(flag ? ans:-1) << endl;

}

