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
const int maxq = 50;
const int maxn = 10;
int n,m,q;
int a[maxq],b[maxq],c[maxq],d[maxq];
int A[maxn];
vector<int> answer;

void dfs(int depth, int last, int A[]){
    if(depth == n){
        int ans = 0;
        REP(k,q){
            if(A[b[k]-1] - A[a[k]-1] == c[k]){
                ans+= d[k];
            }
        }
        answer.push_back(ans);

        return;
    }
    FOR(i,last,m+1){ //詰まったポイント　mじゃなくてm+1 for文で単純に回す時以外はfor文で書いた方がいいかも
        A[depth] = i;
        dfs(depth+1,i,A);
    }
}

int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	//cout << fixed << setprecision(15);
    cin >>n>>m>>q;
    REP(i,q){
        cin>>a[i]>>b[i]>>c[i]>>d[i];
    }
    dfs(0,1,A);

    int ans = *max_element(ALL(answer));
    /*REP(i,answer.size()){
        if(answer[i] != 0)
        cout << answer[i] << endl;
    }*/
    cout << ans << endl;
}