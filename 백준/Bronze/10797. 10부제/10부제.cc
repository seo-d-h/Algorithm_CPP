#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, car_num, cnt=0;
    cin >> n;
    for(int i=0;i<5;i++){
        cin >> car_num;
        if(car_num == n) cnt++;
    }
    cout << cnt;
}