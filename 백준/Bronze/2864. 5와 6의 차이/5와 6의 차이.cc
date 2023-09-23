#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string a, b;
    int a1=0,a2=0,b1=0,b2=0;    // 1이 작은수, 2가 큰수

    cin >> a >> b;

    for(int i=0;i<a.length();i++){
        if(a[i] == '5'){
            a2 = (a2*10) + 6;
            a1 = (a1*10) + a[i]-'0';
            continue;
        }
        else if(a[i] == '6'){
            a1 = (a1*10) + 5;
            a2 = (a2*10) + a[i]-'0';
            continue;
        }
        else{
            a1 = (a1*10) + a[i]-'0';
            a2 = (a2*10) + a[i]-'0';
        }
    }

    for(int i=0;i<b.length();i++){
        if(b[i] == '5'){
            b2 = (b2*10) + 6;
            b1 = (b1*10) + b[i]-'0';
            continue;
        }
        else if(b[i] == '6'){
            b1 = (b1*10) + 5;
            b2 = (b2*10) + b[i]-'0';
            continue;
        }
        else{
            b1 = (b1*10) + b[i]-'0';
            b2 = (b2*10) + b[i]-'0';
        }
    }
    // cout << a1 << " " << a2 << " " << b1 << " " << b2 << endl;
    cout << min({a1+b1, a1+b2, a2+b1, a2+b2}) << " ";
    cout << max({a1+b1, a1+b2, a2+b1, a2+b2});
    
}