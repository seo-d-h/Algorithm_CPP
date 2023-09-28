#include <iostream>
using namespace std;

int main(){
    int cnt=1;
    string str;
    cin >> str;

    for(int i=0;i<str.length();i++){
        if(str[i] == ',') cnt++;
    }
    cout <<cnt;
}