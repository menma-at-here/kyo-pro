#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include<numeric>
#include <cmath>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int xmax = 5001, ymax = 5001;

/*template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}*/
int main(){
    int n; cin >> n;
    vector<P> node(n);
    bool flag[xmax+1][ymax+1];
    //Fill(flag,false);
    REP(i,xmax){
        REP(k,ymax){
            flag[i][k] = false;
    }
    }
    REP(i,n){
        int x, y; cin >> x >> y;
        flag[x][y] = true;
        node[i] = P(x,y);
    }
    int ans = 0;
    REP(i,n){
        REP(j,n){
            if(i != j){
                int x1 = node[i].first, y1 = node[i].second;
                int x2 = node[j].first, y2 = node[j].second;
                int x3 = x2 -(y2 - y1), y3 = y2 + (x2 - x1);
                if(x3 >= 0 && x3 <= 5000 && y3 >= 0 && y3 <= 5000){
                    int x4 = x3 -(x2 - x1), y4 = y3 - (y2 - y1);
                    if(x4 >= 0 && x4 <= 5000 && y4 >= 0 && y4 <= 5000){
                        if(flag[x3][y3] && flag[x4][y4]){ans = max(ans, (x1-x2)*(x1-x2) +(y1-y2)*(y1-y2) );}
                    }
                }
            }
        }
    }
    cout << ans << endl;
    //return 0;


}