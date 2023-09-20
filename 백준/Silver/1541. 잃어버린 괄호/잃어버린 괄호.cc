#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    int num=0;
    int sum=0;
    int sign = 1;
    cin >> str;
    for(int i=0;i<=str.length();i++){
        if(str[i] == '-' || str[i] == '+' || str[i] == '\0'){
            sum += sign*num;
            if(str[i] == '-'){
                sign = -1;
            }
            num=0;
        }
        else if(num == 0){
            num = str[i] - '0';
        }
        else{
            num = num*10 + (str[i] - '0');
        }
    }
    cout << sum;
}