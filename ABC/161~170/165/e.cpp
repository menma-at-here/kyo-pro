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

int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	//cout << fixed << setprecision(15);

    int n,m; cin >> n>>m;
    int itr = 0;
    if(n % 2 ==1){
        REP(i,m){
            if(i %2 == 0){
                cout << i+1 << " " << n/2 - i +1<<endl;
            }
            else{
                cout << n -i +1<< " "<< n/2 + i +1<< endl;
            }
            //itr++;
            //if(itr == m) break;
        }
    }
    else{
        REP(i,m){
            if(i %2 == 0){
                cout << i+1 << " " << (n-1)/2 - i +1<<endl;
            }
            else{
                cout << n -i +1<< " "<< n/2 + i +1<< endl;
            }
            //itr++;
            //if(itr == m) break;
        }
    }
    
}