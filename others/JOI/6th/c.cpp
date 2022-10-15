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

class Edge{
public:
    P vec;
    P from;
    P to;
    int sq;
    Edge(){

    }

    Edge(P a,P b){
        if(a.first == b.first){
            if(a.second > b.second) {
                vec = P(0, a.second - b.second);
                from = b; to = a;
            }
            else{
                vec = P(0,b.second - a.second);
                from = a; to = b;
            }
        }
        else{
            if(a.first > b.first) {
                vec = P(a.first-b.first, a.second - b.second);
                from = b; to = a;
            }
            else {
                vec = P(b.first - a.first, b.second - a.second);
                from = a; to = b;
            }
        }

        sq = pow(a.first -b.first, 2.0) + pow(a.second - b.second,2.0);
    }
};

bool compare(Edge a, Edge b){
    if(a.sq == b.sq) return(a.vec.second > b.vec.second);
    return a.sq > b.sq;
}
int main(){
    int n; cin >> n;
    vector<P> node(n);
    vector<Edge> E(n*(n-1) / 2);
    REP(i,n){
        int x,y; cin >> x >> y;
        node[i] = P(x,y);
    }
    REP(i,n-1){
        FOR(k,i+1,n){
            E[i] = (Edge(node[i], node[k]));
        }
    }
    ll ans = 0;
    sort(ALL(E), compare);
    //cout << E[0].sq << E[0].vec.first << E[0].vec.second << endl;
    int itr = 0;
    //cout << E.size() << endl;
    //cout << E[34].sq << endl;
    REP(i,E.size()){
        if(i < itr) continue;
        while(E[i].sq == E[itr].sq && E[i].vec.second == E[itr].vec.second && itr < E.size()){
            //cout << E[itr].sq << endl;
            itr++;
        }
        if(i+1 < itr){
            //cout << i << " " << itr << endl;
            REP(k,itr-1){
                for(int l = k+1; l<= itr; l++){
                    if(E[k].vec == E[l].vec){
                        if(E[k].vec.first * (E[k].from.first - E[l].from.first) + E[k].vec.second * (E[k].from.second - E[l].from.second) == 0){
                            ans = E[k].sq;
                            cout << ans << endl;
                            return 0;
                        }
                    }
                }
            }
        }
        
        
    }

    cout << ans << endl;
    return 0;

}