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

int a,b,c,x,y;
int main(){
    cin >> a >> b >> c >> x >> y;
    int maxi = max(x,y);
    int mini = min(x,y);
    if(2 * c > a + b){
        cout << a*x + b*y << endl;
    }
    else{
        if(2*c > a && 2*c > b){
            if(x < y){
                cout << mini*2*c + (y-x)*b << endl;
            }
            else{cout << mini*2*c + (x-y)*a << endl;}
        }
        else if(2*c <= a && 2*c <= b){
            cout << 2*c*mini + 2*c*(maxi-mini)<<endl;
        }
        else if(2*c <= a && 2*c > b){
            if(x < y){cout << 2*c*mini + b*(maxi-mini) << endl;}
            else{cout << 2*c*maxi << endl;}
        }
        else{
            if(x<y){cout << 2*c*maxi << endl;}
            else{cout << 2*c*mini + a * (maxi-mini);}
        }
    }
}