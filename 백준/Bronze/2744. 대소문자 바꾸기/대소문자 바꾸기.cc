#include <iostream>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string str;
    string res = "";
    cin >> str;

    for(int i=0;i<str.length();i++){
        if(isupper(str[i])){
            res += tolower(str[i]);
        }
        else if(islower(str[i])){
            res += toupper(str[i]);
        }
    }
    cout << res;
}