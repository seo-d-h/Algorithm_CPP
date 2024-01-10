#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int N;
string str;
int check[30];
bool flag = false;

int main(){
    cin >> N;
    cin >> str;
    
    if(N%2){        // 문자열이 홀수이면
        int mid = floor(N/2);
        for(int i=0;i<N;i++){
            if(i == mid && (N%2)) continue;
            check[str[i]-'a']++;
        }
    }
    else{       // 짝수이면
        for(int i=0;i<N;i++){
            check[str[i]-'a']++;
        }
    }
    
    for(int i=0;i<26;i++){
        if(check[i] % 2){
            flag = true;
            break;
        }
    }
    if(flag) cout << "No";
    else cout << "Yes";
}