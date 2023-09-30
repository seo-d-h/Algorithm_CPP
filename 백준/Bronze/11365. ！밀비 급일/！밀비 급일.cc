#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string str, tmp;
    while(1){
        getline(cin,str);
        if(str == "END") return 0;
        else{
            reverse(str.begin(), str.end());
            cout << str << "\n";
        }
    }
    
}