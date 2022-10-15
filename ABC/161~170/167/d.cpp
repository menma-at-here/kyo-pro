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

/*class teleport{
public:
    ll n,k;
    vector<ll> A;
    vector<bool> flag;
    teleport(){
        cin>>n>>k;
        A.resize(n);
        flag.resize(n,false);
        REP(i,n) {
            cin >> A[i]; A[i]--;
        }
    }

    while(fl)
}

ll tel(ll now){
    if(flag[now] )
}*/

int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	//cout << fixed << setprecision(15);
    ll n,k;
    cin>>n>>k;
    vector<ll> A(n);
    REP(i,n) {
        cin >> A[i]; A[i]--;
    }
    vector<bool> flag(n,false);

    ll start = 0;
    ll itr = 0;
    while(flag[start] == false){
        flag[start] = true;
        start = A[start];
        itr++;
        if(itr == k){
            cout << start+1 << endl;
            return 0;
        }
    }
    vector<ll> loop;
    ll now = start;
    //ll rep = 0;
    do{
        loop.push_back(now);
        //rep++;
        now = A[now];
    }while(now != start);
    //cout << start << endl;
    //cout << itr << " " << loop.size() << endl;
    itr -= loop.size();
    k -= itr;

    ll amari = k % loop.size();
    cout << loop[amari]+1 << endl;
    return 0;
    
    
}