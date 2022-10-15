#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    double L;
    cin >> L;
    long double ans = (L / 3) * (L / 3) * (L / 3);

    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}