#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<long long int> A(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }

    vector<long long int> quan(N + 1);
    for(int i = 0; i < N; i++){
        quan[A[i]]++;
    }
    
    long long int ans = 0;
    for(int i = 0; i < N + 1; i++){
        ans += quan[i] * (quan[i] - 1) / 2;
    }

    for (int i = 0; i < N; i++){
        long long int ansans;
        long long int aa = quan[A[i]] - 1;
        ansans = ans - aa;
        cout << ansans << endl;
    }

    return 0;
}