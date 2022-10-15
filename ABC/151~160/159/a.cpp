#include <iostream>

using namespace std;

int main(){
    int N,M;
    cin >> N;
    cin >> M;

    int ans;
    ans = (N * (N - 1)) / 2 + (M * (M - 1)) / 2;

    cout << ans << endl;

    return 0;
}

