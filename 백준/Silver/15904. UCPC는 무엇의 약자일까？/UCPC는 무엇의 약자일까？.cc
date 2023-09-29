#include <iostream>
#include <string>
using namespace std;

int main(){
    bool f1=false,f2=false,f3=false,f4=false;
    string str;
    getline(cin,str);
    //cin >> str;

    for(int i=0;i<str.length();i++){
        //cout << str[i] << endl;
        if(str[i] == 'U'){
            f1 = true;
        }
        if(str[i] == 'C' && f1){
            f2 = true;
        }
        if(str[i] == 'P' && f1 && f2){
            f3 = true;
        }
        if(str[i] == 'C' && f1 && f2 && f3){
            cout << "I love UCPC";
            return 0;
        }
    }
    cout << "I hate UCPC";
}