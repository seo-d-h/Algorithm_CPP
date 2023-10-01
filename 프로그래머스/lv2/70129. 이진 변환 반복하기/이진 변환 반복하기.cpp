#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    int removed_0 = 0;
    int cnt_changed = 0;
    while(1){
        cnt_changed++;      // 이진변환 횟수 카운트
        string changed = "";
        for(int i=0;i<s.length();i++){
            if(s[i] == '0'){
                removed_0++;
            }
            else{
                changed += s[i];
            }
        }
        int changed_size = changed.length();
        changed = "";
        while(changed_size != 0){       // 0제거 후 길이를 이진수로 변환
            if(changed_size % 2 == 0){
                changed += to_string(0);
            }
            else changed += to_string(1);
            changed_size /= 2;
        }
        reverse(changed.begin(), changed.end());
        //cout << changed << endl;
        s = changed;
        if(s.length() == 1) break;
    }
    answer.push_back(cnt_changed);
    answer.push_back(removed_0);
    
    return answer;
}