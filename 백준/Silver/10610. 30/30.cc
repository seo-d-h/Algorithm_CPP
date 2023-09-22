#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string str;
    int tmp=0;
    cin >> str;
    sort(str.begin(), str.end(), greater<int>());

    for(int i=0;i<str.length();i++){
        if(str[i] != '\0'){
            tmp += str[i] - '0';
        }
    }

    //cout << str.back();
    if(tmp % 3 == 0 && str.back() == '0'){
        cout << str;
    }
    else{
        cout << -1;
    }
}