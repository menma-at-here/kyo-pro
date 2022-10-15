#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include<numeric>
#include<cmath>
#include<map>
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
using vvii = vector<vector<int> >;
using vvll =  vector<vector<ll> >;

const int MAX_INT = 5e5 + 1;
const ll inf = 1LL << 60;

struct Point{
    int queri;
    int x,y;
    int bangou;

    Point(int q, int xx, int yy, int bb){
        queri = q;
        x = xx;
        y = yy;
        bangou = bb;
    }
};

struct BIT{
    int N;
    vector<int> bit;

    BIT(int n_){
        N = n_;
        /*while(n_ > N){
            N *= 2;
        }*/
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

bool for_sort(Point p1, Point p2){
    if(p1.x == p2.x){
        return p1.queri < p2.queri;
    }
    else{
        return p1.x > p2.x;
    }
}

int main(){
    int N,Q; cin >> N >> Q;
    vector<int> last(N,-1);
    vector<Point> point;
    

    REP(i,N){
        int c; cin >> c;
        c--;
        if(last[c] != -1){
            point.push_back(Point(0, last[c], i+1, -1));
        }
        last[c] = i+1;
    }
    REP(i,Q){
        int l,r;
        cin >> l >> r;
        //l--; r--;
        point.push_back(Point(1,l,r, i));
    }

    sort(ALL(point), for_sort);
    /*REP(i,point.size()){
        cout << point[i].queri << " " << point[i].x << " " << point[i].y << endl;
    }*/

    int itr = 0;
    BIT tree(MAX_INT);
    vector<int> ans(Q);

    for(int line = MAX_INT; line != 0; line--){
        while(point[itr].x == line && itr < point.size()){
            if(point[itr].queri == 0){
                tree.add(point[itr].y + 1 ,1);
            }
            else{
                int now = tree.sum(point[itr].y+1);
                int ban = point[itr].bangou;
                ans[ban] = point[itr].y - point[itr].x + 1 - now;
            }
            itr++;
        }
    }

    REP(i,ans.size()){
        cout << ans[i] << endl;
    }
    
}
