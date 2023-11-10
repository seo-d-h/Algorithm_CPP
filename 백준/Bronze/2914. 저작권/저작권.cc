#include <iostream>
using namespace std;

int main(){
    int A, I, cnt = 1;
    cin >> A >> I;

    while(1){
        if(cnt/A >= I-1){
            break;
        }
        cnt++;
    }
    cout << cnt+1;
}