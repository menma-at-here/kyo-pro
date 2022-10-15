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

const ll inf = 1LL << 60;

struct Segment_Tree{
    int N;
    vector<int> dat;
    Segment_Tree(int n_){
        N = 1;
        while(n_ > N){
            N *= 2;
        }
        dat.resize(2*N - 1, INF); //ここのINFは、何を求めたいかにより変更
    }

    /*void init(int q, int a){
        q = q + N - 1;
        dat[q] = a;
        while(q > 0){
            q = (q-1) / 2;
            dat[q] = min(dat[2*q + 1],dat[2*q + 2]);
        }
    }*/

    void update(int q, int a){
        q = q + N -1;
        dat[q] = a;
        while(q > 0){
            q = (q-1) / 2;
            dat[q] = min(dat[2*q + 1],dat[2*q + 2]);  //ここは何を求めたいかにより変更
        }
    }

    int queri_sub(int a, int b, int k, int l, int r){ //[a, b)の最小値を求める　kは節点(何番目の箱？を考えてるか) [l,r)の範囲を考える (最初は[0,N) )
        // → 最初は (a, b, 0 , 0 , N)って感じになる
        if(a >= r || b <= l){
            return INF; //何を求めたいかにより変更
        }
        else if(a <= l && b >= r){
            return dat[k];
        }

        else{
            int left = queri_sub(a, b, k*2 + 1, l, (l+r) / 2);
            int right = queri_sub(a, b, k*2 + 2, (l+r) / 2, r);
            return min(left,right); //何を求めたいかにより変更
        }
    }

    int queri(int a,int b){
        return queri_sub(a,b,0,0,N);
    }


};

int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	//cout << fixed << setprecision(15);
    int N,Q; cin >>N>>Q;
}