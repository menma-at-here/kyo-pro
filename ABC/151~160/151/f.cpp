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

const ll inf = 1LL << 60;
vector<pdd> points;
int N;


double calc_dist(pdd p1, pdd p2){
	double res = pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2);
	return sqrt(res);
}

double calc_r(pdd p){
	double maxi = 0;
	REP(i,N){
		maxi = max(maxi, calc_dist(p, points[i]));
	}
	return maxi;
}

double tripley(double x1){
	double left = 0;
	double right = 1000;
	while(right - left > pow(10,-8)){
		double nowl = (2*left + right) / 3;
		double nowr = (left + 2*right) / 3;
		double leftmax = calc_r(pdd(x1,nowl));
		double rightmax = calc_r(pdd(x1, nowr));
		if(leftmax > rightmax) left = nowl;
		else right = nowr;
	}
	return left;
}

pdd triplex(){
	double left = 0;
	double right = 1000;
	while(right - left > pow(10,-8)){
		double c1 = (2*left + right) / 3;
		double c2 = (left + right*2) / 3;
		double y1 = tripley(c1);
		double y2 = tripley(c2);
		if(calc_r(pdd(c1,y1)) > calc_r(pdd(c2,y2))) left = c1;
		else right = c2;
	}

	return pdd(left, tripley(left));
}

int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(15);
	cin >> N;
	points.resize(N);
	
	REP(i,N){
		double x,y; cin>>x >>y;
		points[i] = pdd(x,y);
	}
	
	//cout << minx << " " << miny << endl;
	pdd ansp = triplex();
    //cout << ansp.first << " " << ansp.second << endl;
	cout << calc_r(ansp) << endl;
}