#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include<numeric>
#include<cmath>
#include <iomanip>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
static const double pi = 3.141592653589793;

int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(15);
    double A,B,H,M; cin >>A>>B>>H>>M;
    double hx,hy,mx,my;
    //double hour = H + 
    hx = A * cos(pi * (H + (M/60)) / 6);
    hy = A * sin(pi * (H + (M/60)) / 6);
    mx = B * cos(pi * M / 30);
    my = B * sin(pi * M / 30);

    double distance = sqrt(pow(hx - mx ,2.0) + pow(hy - my,2.0));

    cout << distance << endl;
}