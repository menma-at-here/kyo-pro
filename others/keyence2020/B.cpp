#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
const int Max_N = 100000;

int N;
typedef pair <int ,int> P;
vector<P> robot;
bool compare(P a, P b){
    return a.first + a.second < b.first + b.second;

}
int main(){
    cin >> N;
    REP(i,N){
        int first,second;
        cin >> first >> second;
        P p(first,second);
        robot.push_back(p);
    }
    sort(ALL(robot),compare);

    int count = 1;
    P robo = robot[0];
    REP(i,N){
        int x = robot[i].first - robot[i].second;
        if(x >= robo.first + robo.second){
            count++;
            robo = robot[i];
        }
    }
    /*REP(i,N){
        printf("%d %d\n",robot[i].first,robot[i].second);
    }*/
    cout << count << endl;
}