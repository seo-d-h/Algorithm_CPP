#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> vec;
    int tmp=0;
    int mini = 99999999;
    int maxi = -9999999;
    int sign = 1;
    for(int i=0;i<s.length();i++){
        if(s[i] == '-'){
            sign = -1;
            continue;
        }
        if(s[i] != ' '){
            tmp = tmp*10 + sign*(s[i] - 48);
            //cout << "tmp :" << tmp << endl;
        }
        else{
            mini = min(mini, tmp);
            maxi = max(maxi, tmp);
            sign = 1;
            tmp = 0;
        }
    }
    mini = min(mini, tmp);
    maxi = max(maxi, tmp);
    
    // cout << mini << " " << maxi;
    answer += to_string(mini);
    answer += " ";
    answer += to_string(maxi);
    
    return answer;
}