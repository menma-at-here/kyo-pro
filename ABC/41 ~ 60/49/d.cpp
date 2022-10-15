#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
//auto Tuple = tuple<int,int,int>;
//typedef pair<int,int> P;
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

	//自分のいるグループの頂点数を調べる
	/*int size(int A) {
		return -Parent[root(A)];//親をとってきたい]
	}*/

	//AとBをくっ付ける
	void connect(int A, int B) {
		//AとBを直接つなぐのではなく、root(A)にroot(B)をくっつける
		A = root(A);
		B = root(B);
		if (A == B) {
			//すでにくっついてるからくっ付けない
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
//tuple<int,int,int> test;
bool compare1(tuple<int,int,int> x,tuple<int,int,int> y){
    if(get<0>(x) == get<0>(y)) {return get<1>(x) < get<1>(y);}
    return get<0>(x) < get<0>(y);
}

int main(){
    cin.tie(0);
	ios::sync_with_stdio(false);
	//cout << fixed << setprecision(10);
    int N,K,L;
    cin >> N>>K>>L;
    int p[K], q[K], r[L], s[L];
    REP(i,K){
        cin >> p[i]>> q[i];
    }
    REP(i,L){
        cin >> r[i] >> s[i];
    }

    UnionFind road(N),train(N);
    vector<tuple<int,int,int> > uni;
    //int ans[N];
    REP(i,K){
        road.connect(p[i]-1,q[i]-1);
    }
    REP(i,L){
        train.connect(r[i]-1,s[i]-1);
    }
    REP(i,N){
         //p(road.root(i), train.root(i));
        uni.push_back(make_tuple(road.root(i), train.root(i), i));
    }
    sort(ALL(uni),compare1);
    
    int front = 0;
    int back = 1;
    vector<int> ans(N,0);
    while(front < N-1){
        while(get<0>(uni[front]) == get<0>(uni[back]) && get<1>(uni[front]) == get<1>(uni[back]) && back < N){
            back++;
        }
        for(int i = front; i <back;i++){
            ans[get<2>(uni[i])] += back-front;
        }
        front = back;
        back++;
        if(front == N - 1){
            ans[get<2>(uni[N-1])]++;
        }
    }
    REP(i,N){
        cout << ans[i] << endl;
    }
    /*map<pair<int, int>, int> ma;
	rep(i, n) {
		pair<int, int> p(uf.root(i), uf2.root(i));
		ma[p]++;
	}
 
	rep(i, n) {
		pair<int, int> p(uf.root(i), uf2.root(i));
		cout << ma[p] << " ";
	}*/ //こんな書き方もあります…
 
}

