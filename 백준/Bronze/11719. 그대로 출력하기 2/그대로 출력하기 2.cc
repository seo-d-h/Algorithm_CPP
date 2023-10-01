#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(1){
        string str;
        getline(cin, str);
        if(cin.eof()) break;
        cout << str << "\n";
    }
}