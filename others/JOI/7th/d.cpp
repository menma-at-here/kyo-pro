#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include<numeric>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int n,m;

bool compare(P a,P b){
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}
int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	//cout << fixed << setprecision(15);
    cin >> m;
    vector<P> sign(m);
    REP(i,m){
        int x,y; cin >> x >> y;
        sign[i] = P(x,y);
    }

    cin >> n;
    vector<P> star(n);
    REP(i,n){
        int x,y; cin >> x >> y;
        star[i] = P(x,y);
    }
    sort(ALL(sign),compare);
    sort(ALL(star),compare);
    
    REP(i,n){
        int dx = star[i].first - sign[0].first;
        int dy = star[i].second - sign[0].second;
        bool ans = true;
        REP(j,m){
            if(!binary_search(ALL(star), P(sign[j].first + dx, sign[j].second + dy))){
                ans = false; break;
            }
        }
        if(ans){
            cout << dx  << " " << dy << endl;
            //cout << dy << endl;
        }
    }    

}