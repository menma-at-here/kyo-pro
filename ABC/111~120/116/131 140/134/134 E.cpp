#include <bits/stdc++.h>
using namespace std;


int main(){
    int N;
    vector<int> A(N);
    cin >> N;
    for(int i = 0;i < N; i++){
        cin >> A.at(i);
    }
    vector<int> dp(1);
    dp.at(0) = (A.at(0));

    //dpの二つ目までを求める
    int cont_i;
    for (int i=0; i<N; i++){
        if (dp.at(0) < A.at(i)){
            dp.at(0) = A.at(i);
        }
        else{
            cont_i = i;
            dp.insert(dp.begin(), A.at(i));
            break;
        }       
    }

    for(int k = cont_i; k<N; k++){
        if (dp.at(0) >= A.at(k)){
            dp.insert(dp.begin(), A.at(k));
        }

        else if (dp.at(dp.size()-1) < A.at(k)){
            dp[dp.size()-1] = A.at(k);
        }

        else{
            for(int i=0; i<dp.size()-1; i++){
                if((dp.at(i) < A.at(k)) && (A.at(k) <= dp.at(i))){
                    dp.at(i) = A.at(k);
                    break;
                }
            }
        }
    }
    cout << dp.size() << endl;
}