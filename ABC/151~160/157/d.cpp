#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<algorithm>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
using vvi = vector<vector<int> >;
const int max_n = 100000;
const int max_m = 100000;
using namespace std;

class UnionFind {
public:
	//親の番号を格納する。親だった場合は-(その集合のサイズ)
	vector<int> Parent;

	//作るときはParentの値を全て-1にする
	//こうすると全てバラバラになる
	UnionFind(int N) {
		Parent = vector<int>(N, -1);
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


int main() {
	int N,M,K;
	cin>>N>>M>>K;
	UnionFind uni(N);
	vvi tomo(N), block(N);
	REP(i,M){
		int a,b; 
		cin >>a>>b; a--,b--;
		tomo[a].push_back(b);
		tomo[b].push_back(a);
		uni.connect(a,b);
	}
	REP(i,K){
		int c,d; cin>>c>>d; c--; d--;
		block[c].push_back(d);
		block[d].push_back(c);
	}
	vector<int> ans(N,0);
	REP(i,N){
		int now = uni.size(i)-tomo[i].size()-1;
        REP(k,block[i].size()){
            if(uni.root(i) == uni.root(block[i][k])){
                now--;
            }
        }
        ans[i] = now;
	}
    REP(i,N-1){
        cout << ans[i] <<" ";
    }
    cout<<ans[N-1]<<endl;
}