#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    int arr[12];

    arr[1] = 0;
    arr[2] = 1;
    cin >> n;

    if(n == 1){
        cout << 0;
    }
    else{
        for(int i=3;i<=n;i++){
            arr[i] = i-1 + arr[i-1];
        }
        cout << arr[n];
    }

    return 0;
}