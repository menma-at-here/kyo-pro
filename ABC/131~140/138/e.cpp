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
const int numa = 26;
const int maxn = 100006;

int main(){
    //cin.tie(nullptr);
	//ios_base::sync_with_stdio(false);
	//cout << fixed << setprecision(15);
    string s,t;
    cin >>s;
    cin >>t;
    vector<vector<int> > alpha(numa);
    REP(i,s.length()){
        int numnow = s[i] - 'a';
        //cout << numnow <<endl;
        alpha[numnow].push_back(i+1);
    }

    ll loop = 0;
    bool cando = true;
    ll where = -1;

    REP(i,t.length()){
        int numnow = t[i] - 'a';
        //cout << alpha[numnow].size() << endl;
        if(alpha[numnow].size() == 0){
            cando = false;
            break;
        }

        auto itr = upper_bound(ALL(alpha[numnow]),where);
        if(itr != alpha[numnow].end()){
            where = *itr;
        }
        else{
            loop++;
            where = alpha[numnow][0];
        }
    }
    //cout << loop << where << endl;
    cout << (cando ? loop * (ll)s.length() + where : -1) << endl;
}

