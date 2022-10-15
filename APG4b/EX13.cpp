#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  int i,k = 0;
  int sum,ave = 0;
  vector<int> score(N);

  for(i=0; i<N; i++){
      cin >> score.at(i);
      sum += score.at(i);
  }
  ave = sum / N;

  for(k=0; k<N; k++){
      cout << abs(ave - score.at(k)) << endl;
  }
}
