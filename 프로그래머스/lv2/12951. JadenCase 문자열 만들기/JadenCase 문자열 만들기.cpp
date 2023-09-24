#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    bool flag = 0;      
    
    answer += toupper(s[0]);
    
    for(int i=1;i<s.length();i++){      // 일단 전부 소문자화
        s[i] = tolower(s[i]);
    }
    
    for(int i=1;i<s.length();i++){
        if(flag == 1){
            answer += toupper(s[i]);
            flag = 0;
        }
        else{
            answer += s[i];
        }
        if(s[i] == ' '){
            flag = 1;
        }
    }
    
    //cout << s;
    

    return answer;
}