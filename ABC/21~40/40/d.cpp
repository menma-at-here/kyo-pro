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
const int max_n = 100000;
const int max_m = 200000;
typedef pair<int,int> P;
using namespace std;

struct bridge{
    int a;
    int b;
    int y;
    bridge(){

    }
    bridge(int aa, int bb, int yy){
        a = aa;
        b = bb;
        y = yy;
    }
};

struct People{
    int place;
    int origin;
    int y;
    People(){

    };
    People(int p,int o, int yy){
        place = p;
        origin = o;
        y = yy;
    }
};

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

bool compare1(bridge a, bridge b){
    return a.y > b.y;
}

bool compare2(People a, People b){
    return a.y > b.y;
}
int main() {
	int N, M;
	cin >> N >> M;
	vector<bridge> vec(M);
    REP(i,M){
        int a,b,y;
        cin >> a>>b>>y;
        a--; b--;
        vec[i] = bridge(a,b,y);
    }
    sort(ALL(vec),compare1);

    int Q; cin>>Q;
    vector<People> people(Q);
    REP(i,Q){
        int v,w;cin>>v>>w;
        v--;
        people[i] = People(v,i,w);
    }
    sort(ALL(people),compare2);

    int itr1 = 0, itr2 = 0;
    UnionFind uni(N);
    vector<int> ans(Q);

    while(true){
        if(itr1 <= M-1 && vec[itr1].y > people[itr2].y){
            uni.connect(vec[itr1].a, vec[itr1].b);
            itr1++;
        }
        else{
            ans[people[itr2].origin] = uni.size(people[itr2].place);
            itr2++;
        }
        if(itr2 == Q) break;
    }
    REP(i,Q){
        cout << ans[i] << endl;
    }
}

