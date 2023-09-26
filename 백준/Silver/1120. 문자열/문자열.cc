#include <iostream>
#include <string>
#include <algorithm>
#include <limits.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s1, s2;
    cin >> s1 >> s2;
    
    int len = s2.length() - s1.length();
    int mini = INT_MAX;

    if(s1.length() == s2.length()){
        int cnt = 0;
        for(int j=0;j<s1.length();j++){
            if(s1[j] != s2[j]){
                cnt++;
            }
        }
        cout << cnt;
        return 0;
    }
    else{
        for(int i=0;i<=len;i++){
            int cnt = 0;
            for(int j=0;j<s1.length();j++){
                if(s1[j] != s2[j+i]){
                    cnt++;
                }
            }
            mini = min(mini, cnt);
        }
        cout << mini;
    }
    
}