#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A;
  cin >> N >> A;
  
  if (N <0){
    for (int i=0;i <N; i++){
        string op;
        int B;
        cin >>op >> B;
        if (op == "/" && B == 0){
            cout << "eroor" <<endl;
            break;
        }
        else{
            if (op == "+"){
                A = A + B;           
            }
            else if (op == "-"){
                A = A - B;
            }
            else if (op == "*"){
                A = A * B;
            }
            else if (op == "/"){
                A = A / B;
            }
            cout << i + 1 << ":" << A <<endl;
        }
    }
  }
  else{
      cout <<"1:" <<A << endl;
  }
}