#include <iostream>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str;
    
    while(1){
        int small=0, big=0, num=0, space=0;
        getline(cin,str);
        if(cin.eof()) break;
        else{
            for(int i=0;i<str.length();i++){
                if(str[i] >= 97 && str[i] <= 122){
                    small++;
                }
                else if(str[i] >= 65 && str[i] <= 90){
                    big++;
                }
                else if(str[i] >= 48 && str[i] <= 57){
                    num++;
                }
                else if(str[i] == ' '){
                    space++;
                }
            }
            cout << small << " " << big << " " << num << " " << space << "\n";
        }
    }
    
}