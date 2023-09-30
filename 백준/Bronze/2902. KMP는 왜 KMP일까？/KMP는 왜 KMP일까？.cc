#include <iostream>
#include <string>
//#include <cctype>
using namespace std;

int main(){
    string str, res="";
    cin >> str;
    for(int i=0;i<str.length();i++){
        if(isupper(str[i])) res += str[i];
    }
    cout << res;
}