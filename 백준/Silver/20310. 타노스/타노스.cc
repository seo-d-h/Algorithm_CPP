#include <iostream>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int cnt_0 = 0, cnt_1 = 0;
    string S;
    string res = "";
    cin >> S;

    for(int i=0;i<S.length();i++){
        if(S[i] == '0') cnt_0++;
        else if(S[i] == '1') cnt_1++;
    }
    //cout << cnt_0 << " " << cnt_1;

    for(int i=0;i<cnt_0/2;i++){
        res += '0';
    }
    for(int i=0;i<cnt_1/2;i++){
        res += '1';
    }
    cout << res;
}