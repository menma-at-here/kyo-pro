#include <iostream>
#include <string>

using namespace std;

int hantei(string s){
    int flag = 0;
    int len = s.size() / 2;
    if (len != 0){
        for(int i = 0; i < len ; i++){
            if(s[i] == s[s.size() - i - 1]){
                if(i == len - 1){flag = 1;}
                else{continue;}
            }
        else{break;}
        }
    }
    else{
        flag = 1;
    }

    return flag;
}

int main(){
    string s, s1,s2;
    cin >> s;
    int N = s.size();
    s1 = s.substr(0,(N - 1)/ 2);
    s2 = s.substr((N + 1) / 2, (N - 1) / 2);

    int flag = 0;
    string ans;

    int f = hantei(s);
    int f1 = hantei(s1);
    int f2 = hantei(s2);

    if (f == 1 && f1 == 1 && f2 == 1){
        ans = "Yes";
    }
    else{ans = "No";}

    cout << ans << endl;

    return 0;

}
