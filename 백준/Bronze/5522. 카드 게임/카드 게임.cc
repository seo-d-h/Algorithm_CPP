#include<iostream>
using namespace std;

int main(){
    int num, res = 0;
    for(int i=0;i<5;i++){
        cin >> num;
        res += num;
    }
    cout << res;
}