#include <bits/stdc++.h>
using namespace std;
 
int main() {
    vector<int> height(3);
    for(int i = 0; i<3; i++){
        cin >> height.at(i);
    }

    sort(height.begin(), height.end());
    cout << height.at(2) - height.at(0) << endl;
}