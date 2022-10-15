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

int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	//cout << fixed << setprecision(15);
    int x; cin >>x;
    vector<int> divisi;

    for(int i = 1; i*i <= x; i++){
        if(x % i == 0){
            divisi.push_back(i);
            divisi.push_back(x / i);
        }
    }
    sort(ALL(divisi));

    for(int a = 0; pow(a,5) <= x; a++){
        REP(k,divisi.size()){
            int b = divisi[k] - a;
            if(b >= 0 && pow(a,5) + pow(b,5) == x){
                cout << a << " " << -b << endl;
                return 0;
                if(pow(a,5) + pow(b,5) > x) break;
            }
        }
    }
    //int a = 0;
    bool flag = false;
    for(int a = 0; pow(a,4) <= x ; a++){
        //cout << a << endl;
        REP(k, divisi.size()){
            int b = a - divisi[k];
            if(pow(a,4) + pow(b,4) > x) break;
            if(b >= 0){
                //cout << a << " " << b << endl;
                if(pow(a,5) - pow(b,5) == x){
                    cout << a << " " << b << endl;
                    flag = true;
                    break;
                    //return 0;
                }
                else continue;
            }
            if(flag) break;
        }
        if(flag) break;
    }
    //cout << "bad" << endl;
    return 0;
}