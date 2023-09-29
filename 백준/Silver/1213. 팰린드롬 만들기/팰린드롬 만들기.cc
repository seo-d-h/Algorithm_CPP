#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string str, res, str_tmp;
    int cnt = 0;
    char tmp = '\0';
    map<char, int> mp;
    cin >> str;

    for(int i=0;i<str.length();i++){
        if(mp.find(str[i]) != mp.end()){
            mp[str[i]]++;
        }
        else{
            mp.insert({str[i], 1});
        }
    }

    for(auto a : mp){
        if(a.second % 2 == 1){
            tmp = a.first;
            cnt++;
        }
        for(int i=0;i<a.second / 2;i++){
            res += a.first;
        }
        if(cnt >= 2){
            cout << "I'm Sorry Hansoo";
            return 0;
        }
    }

    str_tmp = res;
    reverse(str_tmp.begin(), str_tmp.end());
    if(tmp != '\0') res += tmp;
    res += str_tmp;
    cout << res;
}