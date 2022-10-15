#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
typedef long long ll;
typedef pair<int,int> P;
const int max_n = 100000;
const int max_m = 100000;


class UnionFind {
public:
	//親の番号を格納する。親だった場合は-(その集合のサイズ)
	vector<int> Parent;
    vector<int> Rank;

	//作るときはParentの値を全て-1にする
	//こうすると全てバラバラになる
	UnionFind(int N) {
		Parent = vector<int>(N);
        Rank = vector<int> (N,1);
        for(int i = 0;i < N;i++){
            Parent[i] = i;
        }
	}

	//Aがどのグループに属しているか調べる
	int root(int A) {
		if (Parent[A] == A) return A;
		return Parent[A] = root(Parent[A]);
	}

	//AとBをくっ付ける
	void connect(int A, int B) {
		//AとBを直接つなぐのではなく、root(A)にroot(B)をくっつける
		A = root(A);
		B = root(B);
		if (A == B) {
			return ;
		}

		if (Rank[A] < Rank[B]) Parent[A] = B;
		
		else{
            Parent[B] = A;
            if(Rank[A] == Rank[B]) Rank[A]++;
        }
		return;
	}
    bool find(int A,int B){
        return root(A) == root(B);
    }
};

int N,M;
vector<int> p(max_n,0);

int main(){
    cin >> N >> M;
    UnionFind number(N);
    REP(i,N){
        cin >> p[i];
        p[i]--;
    }
    REP(i,M){
        int x,y;
        cin >> x >> y;
        x--, y--;
        number.connect(x,y);
    }

    int ans = 0;
    REP(i,N){
        if(number.root(i) == number.root(p[i])){
            ans++;
        }
    }
    cout << ans << endl;
}