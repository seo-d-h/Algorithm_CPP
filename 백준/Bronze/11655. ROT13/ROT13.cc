#include <iostream>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string str;
    string res = "";
    getline(cin, str);

    for(int i=0;i<str.length();i++){
        if(str[i] >= 78 && str[i] <= 90){
            for(int j=0;j<13;j++){
                str[i]++;
                if(str[i] > 90) str[i] = 65;
            }
            res += str[i];
        }
        else if(str[i] >= 110 && str[i] <= 122){
            for(int j=0;j<13;j++){
                str[i]++;
                if(str[i] > 122) str[i] = 97;
            }
            res += str[i];
        }
        else if(str[i] == ' '){
            res += ' ';
        }
        else if(str[i] >= 65 && str[i] <= 77 || str[i] >= 97 && str[i] <= 109){
            res += str[i] + 13;
        }
        else{
            res += str[i];
        }
    }
    cout << res;
}