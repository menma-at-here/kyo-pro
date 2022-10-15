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

struct BIT{
    int N;
    vector<int> bit;

    BIT(int n_){
        N = 1;
        while(n_ > N){
            N *= 2;
        }
        bit.resize(N,0);
    }

    int sum(int i){  //1 ~ i までの和を求める
        int ans = 0;
        while(i > 0){
            ans += bit[i];
            i -= (i & -i);
        }
        return ans;
    }

    void add(int i, int x){ //i番目にxを加える
        while(i <= N){
            bit[i] += x;
            i += (i & -i);
        }
    }
    
};

int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	//cout << fixed << setprecision(15);

    
}