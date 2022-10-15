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
    ll N ; cin >> N;

    vector<ll> diff(N);
    vector<ll> sum(N);

    REP(i,N){
        int a; cin >> a;
        diff[i] = i-a;
        sum[i] = i+a;
    }

    sort(ALL(diff));
    sort(ALL(sum));
    ll ans = 0;

    ll itr_d = 0, itr_s = 0;
    while(diff[itr_d] <= 0){
        itr_d++;
    }

    while(itr_d < N){
        if(diff[itr_d] == sum[itr_s]){
            ans+= (upper_bound(ALL(diff),diff[itr_d])-lower_bound(ALL(diff),diff[itr_d])) * (upper_bound(ALL(sum),sum[itr_s])-lower_bound(ALL(sum),sum[itr_s]));
            itr_d += upper_bound(ALL(diff),diff[itr_d])-lower_bound(ALL(diff),diff[itr_d]);
            itr_s += upper_bound(ALL(sum),sum[itr_s])-lower_bound(ALL(sum),sum[itr_s]);
        }
        else if(diff[itr_d] > sum[itr_s]){
            while(sum[itr_s] < diff[itr_d])itr_s++;
        }
        else{
            while(sum[itr_s] > diff[itr_d])itr_d++;
        }
    }

    cout << ans << endl;
    /*vector<P> height;
    vector<P> number;
    REP(i,N){
        int a; cin >> a;
        number.push_back(P(a,i));
        height.push_back(P(a,i));
    }
    sort(ALL(height));

    for(int diff = 2; diff <= N-1; diff++){
        for(int hh = 1; hh <= diff /2 ; hh++){
            int itr_high = lower_bound() - height.begin();
        }
    }*/
    


}