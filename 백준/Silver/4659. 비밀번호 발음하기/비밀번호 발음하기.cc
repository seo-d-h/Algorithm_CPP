#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool check_vowel(string check){
    for(int i=0;i<check.length();i++){
        if(check[i] == 'a' || check[i] == 'e' || check[i] == 'i' || check[i] == 'o'|| check[i] == 'u'){
            return true;
        }
    }
    return false;
}

bool check_continuous(string check){
    int consonant_cnt = 0;
    int vowel_cnt = 0;
    for(int i=0;i<check.length();i++){
        if(check[i] == 'a' || check[i] == 'e' || check[i] == 'i' || check[i] == 'o'|| check[i] == 'u'){
            consonant_cnt=0;
            vowel_cnt++;
            if(vowel_cnt >= 3) return false;
        }
        else{
            vowel_cnt=0;
            consonant_cnt++;
            if(consonant_cnt >= 3) return false;
        }
    }
    return true;
}

bool check_twice(string check){
    for(int i=1;i<=check.length();i++){
        if(check[i] != 'e' && check[i] != 'o' && check[i] == check[i-1]){
            return false;
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while(1){
        string str;
        cin >> str;
        if(str == "end") return 0;

        if(check_vowel(str) && check_continuous(str) && check_twice(str)){
            cout << "<" << str << "> is acceptable.\n";
        }
        else{
            cout << "<" << str << "> is not acceptable.\n";
        }
    }
}