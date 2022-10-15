#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> data(5);
  for (int i = 0; i < 5; i++) {
    cin >> data.at(i);
  }

  // dataの中で隣り合う等しい要素が存在するなら"YES"を出力し、そうでなければ"NO"を出力する
  // ここにプログラムを追記
  for (int k = 0; k<4; k++){
      if(data.at(k) == data.at(k+1)){
          cout << "YES" << endl;
          break;
      }
      else if (data.at(k) != data.at(k+1)){
          if(k != 3){
              continue;
          }
          else if(k == 3){
              cout << "NO" <<endl;
          } 
      }
      
  }
}

