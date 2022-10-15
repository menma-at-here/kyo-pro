#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int N,M;
typedef pair<int,int> P;
vector<P> island_bsort;
//vector<P> island_asort;

bool compare(P a,P b){
    return a.second < b.second;
}

int main(){
    cin >> N >> M;
    int a[M], b[M];
    REP(i,M){
        cin >> a[i] >> b[i];
        island_bsort.push_back(P(a[i],b[i]));
        //island_asort.push_back(P(a[i],b[i]));
    }
    //sort(ALL(island_asort));
    sort(ALL(island_bsort),compare);
    int flag[M];
    REP(i,M){flag[i] = 1;} //i番目の橋が通れなくなったかどうかをメモ　まだ通れれば１

    int count = 0;
    int num_island = 0; //今なんばんめの島まで来てるか
    REP(i,M){
        if(num_island <= island_bsort[i].first){
            count++;
            num_island = island_bsort[i].second;
        }
    }
    cout << count << endl;
}