#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include<numeric>
#include<cmath>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> pll;
typedef vector<vector<int> > vvi;
typedef vector<vector<ll> > vll;
const ll inf = 1LL << 60;

int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	//cout << fixed << setprecision(15);
    int X,N;cin>>X>>N;
    int p[N];
    vector<bool> flag(200,true);
    REP(i,N){
        cin>>p[i];
        flag[p[i]] = false;
        }

    if(flag[X] == true){
        cout << X << endl;
        return 0;
    } 
    else{
        int itr = 1;
        while(true){
            if(X-itr >= 0 && flag[X-itr] == true){
                cout<<X-itr<<endl;
                return 0;
            }
            else if(flag[X+itr] == true){
                cout<<X+itr<<endl;
                return 0;
            }
            itr++;
        }
    }

}