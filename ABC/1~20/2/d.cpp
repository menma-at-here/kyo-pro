#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include<numeric>
#include <bitset>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

bool compare(P a,P b){
    if(a.first == b.first) return a.second < b.second;
    else return a.first < b.first;
}
int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	//cout << fixed << setprecision(15);
    int n,m;
    cin >> n >> m;

    int x[m],y[m];
    REP(i,m){
        cin >> x[i] >> y[i];
        x[i]--; y[i]--;
    }
    vector<P> giin(m);
    REP(i,m){
        giin[i] = P(x[i],y[i]);
    }
    sort(ALL(giin),compare);
    int ans = 1;

    for(int bit= 0; bit < (1<<n); bit++){
        int t= bitset<32>(bit).count();
        if(t <= ans)continue;
        bool flag = true;
        int sum = 0;
        for(int k=0; k<n-1; k++){
            for(int l=k+1; l<n; l++){
                /*if(binary_search(ALL(giin),P(k,l),compare) && (bit & (1<<k)) && (bit & (1<<l))){
                    sum++;
                }*/
                if((!binary_search(ALL(giin),P(k,l),compare)) && (bit & (1<<k)) && (bit & (1<<l))){
                    flag = false; break;
                }
            }
            if(!flag) break;
        }

        if(flag) {
            //if(sum == 1) ans = max(ans,sum+1);
            //else{
                /*REP(i,n-1){
                    if(sum ==  (i*(i+1)) /2) {ans = max(ans,i+1);}
                }*/
                ans = t;
            //}
        }
    }

    cout << ans << endl;
}