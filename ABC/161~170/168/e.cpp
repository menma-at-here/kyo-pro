#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include<numeric>
#include<cmath>
#include <queue>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<long double, int> lp;
typedef long double ld;
const ll mod  =1e9 + 7;
const ll max_n = 200010;
vector<ll> fac(max_n);
vector<ll> ifac(max_n);
const ld inf = 1e30;

int N;
ll mpow(int x, int n){
    ll ans = 1;
    REP(i,n){
        ans = ans * x % mod;
    }
    return ans;
}

ll comb(ll a, ll b){
    if(a == 0 && b == 0) return 1;
    if(a < 0 || b < 0) return 0;
    ll tmp = ifac[b] * ifac[b] % mod;
    return tmp * fac[a] % mod;
}

class UnionFind {
public:
	//親の番号を格納する。親だった場合は-(その集合のサイズ)
	vector<int> Parent;

	//作るときはParentの値を全て-1にする
	//こうすると全てバラバラになる
	UnionFind(int N) {
		Parent = vector<int>(N, 0);
	}

	//Aがどのグループに属しているか調べる
	int root(int A) {
		if (Parent[A] < 0) return A;
		return Parent[A] = root(Parent[A]);
	}

	//自分のいるグループの頂点数を調べる
	int size(int A) {
		return -Parent[root(A)];//親をとってきたい]
	}

	//AとBをくっ付ける
	bool connect(int A, int B) {
		//AとBを直接つなぐのではなく、root(A)にroot(B)をくっつける
		A = root(A);
		B = root(B);
		if (A == B) {
			//すでにくっついてるからくっ付けない
			return false;
		}

		//大きい方(A)に小さいほう(B)をくっ付けたい
		//大小が逆だったらひっくり返しちゃう。
		if (size(A) < size(B)) swap(A, B);

		//Aのサイズを更新する
		Parent[A] += Parent[B];
		//Bの親をAに変更する
		Parent[B] = A;

		return true;
	}
};

bool check(ll mid,vector<P(ld,int)> div){
    ll n = div.size();
    vector<ll> second(n);
    bool flag = true;
    
    return (flag);
}

int binary(ld comp, int start, int end,vector<lp> div){
    int ng = start-1, ok = end;
    while(ok - ng > 1){
        int mid = (ng+ok)/2;
        if(abs(div[mid].first - comp) < 1e-10){
            return div[mid].second;
        }
        else if(div[mid].first > comp){
            ok = mid;
        }
        else ng = mid;
    }

    return -1;
}

vector<ld> A,B;
int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	//cout << fixed << setprecision(15);
    fac[0] = 1;
    ifac[0] = 1;
    cin >> N;
    A.resize(N); B.resize(N);
    REP(i,N){
        cin >> A[i] >> B[i];
    }
    REP(i,N){
        fac[i+1] = fac[i] * (i+1) % mod; // fac[i] = n! % mod;
        ifac[i+1] = ifac[i] * mpow(i+1,mod-2) % mod; // ifac[i] = (i!) * pow(i, mod-2) % mod;
    }

    vector<lp> AdivB(N);
    vector<lp> BdivA(N);

    UnionFind uni(N);

    REP(i,N){
        if(B[i] == 0) AdivB[i] = lp(inf , i);
        else AdivB[i] = lp(A[i]/B[i] , i);

        if(A[i] == 0) BdivA[i] = P(inf,i);
        else BdivA[i] = P(B[i]/A[i], i);
    }
    sort(ALL(AdivB));
    sort(ALL(BdivA));
    int num = N;
    REP(i,N){
        if(binary(AdivB[i].first, 0, AdivB.size()+1, BdivA) != -1){
            uni.connect(i,binary(AdivB[i].first, 0, AdivB.size()+1, BdivA));
            num--;
        }
    }
    
    

}