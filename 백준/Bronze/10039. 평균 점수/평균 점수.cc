#include <iostream>
using namespace std;

int main(){
    int a=0, res=0;
    for(int i=0;i<5;i++){
        cin >> a;
        if(a < 40){
            res += 40;
        }
        else res += a;
    }
    cout << res/5;
}