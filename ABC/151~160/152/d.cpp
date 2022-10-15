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
typedef vector<vector<ll> > vvll;
const ll inf = 1LL << 60;

int main(){
    cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	//cout << fixed << setprecision(15);
    int N;cin>>N;
    int keta = 0;
    int top = N;
    int nokori;
    while(true){
        keta++;
        if(top < 10)break;
        top /= 10;    
    }
    int bottom = N % 10;
    nokori = N - top * pow(10,(keta-1)) - bottom;
    //cout << top << " " << bottom << " " << nokori << endl;
    
    vvi number(10,vector<int>(10,0));
    for(int i = 1; i<= 9; i++){
        if(i < top){
            for(int k = 1; k<=9; k++){
                for(int j = 1; j <= keta; j++){
                    if(j == 1 && i == k)number[i][k]++;
                    else if(j==2)number[i][k]++;
                    else{
                        number[i][k] += pow(10,j-2);
                    }
                }
            }
        }
        else if(i == top){
            for(int k = 1; k<=9; k++){
                for(int j = 1; j <= keta; j++){
                    if(j == 1 && i == k)number[i][k]++;
                    else if(j < keta){
                        number[i][k] += pow(10,j-2);
                    }
                    else{
                        if(k <= bottom){
                            if(j == 2)number[i][k]++;
                            else number[i][k] += nokori/10+1;
                            
                        }
                        else{
                            if(nokori/10>=1)number[i][k] += nokori/10;
                        }
                    }
                }
            }
        }
        else{
            for(int k = 1; k<=9; k++){
                for(int j = 1; j < keta; j++){
                    if(j == 1 && i == k)number[i][k]++;
                    else if(j==2)number[i][k]++;
                    else{
                        number[i][k] += pow(10,j-2);
                    }
                }
            }
        }

    }

    /*FOR(i,1,10){
        FOR(k,1,10){
            cout<<number[i][k]<<" ";
        }
        cout<<endl;
    }*/
    int ans = 0;
    FOR(i,1,10){
        FOR(k,1,10){
            ans += number[i][k] * number[k][i];
        }
    }
    cout << ans << endl;
}