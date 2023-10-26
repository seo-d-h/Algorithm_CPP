#include <iostream>
using namespace std;

int main(){
    int a, b, res = 0;
    int cnt=1;
    int arr[1002];
    cin >> a >> b;
    for(int i=1;i<=b;i++){
        for(int j=1;j<=i;j++){
            arr[cnt] = i;
            if(cnt > 1000) break;
            cnt++;
        }
    }
    for(int i=a;i<=b;i++){
        res += arr[i];
    }
    cout << res;
}