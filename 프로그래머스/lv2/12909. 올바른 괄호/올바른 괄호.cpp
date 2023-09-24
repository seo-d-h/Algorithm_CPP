#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> stk;
    
    for(int i=0;i<s.length();i++){
        if(s[i] == '('){
            stk.push('(');
        }
        else if(s[i] == ')'){
            if(!stk.empty()){
                stk.pop();    
            }
            else{
                answer = false;
                break;
            }
        }
    }
    
    if(answer == true && !stk.empty()){
        answer = false;
    }

    return answer;
}