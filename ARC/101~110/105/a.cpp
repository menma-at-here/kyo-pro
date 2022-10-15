#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include<numeric>
#include<cmath>
#include<map>
#include<iomanip>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
using pll = pair<ll,ll>;
using pdd = pair<double,double>;
using vvi = vector<vector<int> >;
using vvll =  vector<vector<ll> >;

int main(){
    //cin.tie(nullptr);
	//ios_base::sync_with_stdio(false);
	//cout << fixed << setprecision(15);
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    bool flag = false;
    int sum = a + b + c + d;
    if(a+b == c + d || a+c==b+d||a+d==b+c)flag = true;
    if (sum - a == a || sum - b == b || sum -c == c|| sum-d==d)flag = true;
    cout <<(flag ? "Yes":"No")<< endl;
}

