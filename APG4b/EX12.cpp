#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int i;
  int count = 1;

  for (i = 1;i < S.size();i += 2){
      if (S.at(i) == '+'){
          count++;
      }
      else if (S.at(i) == '-'){
          count--;
      } 
  }
  cout << count << endl;
}
