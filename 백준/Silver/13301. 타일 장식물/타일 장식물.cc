#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    int a[82];
    cin >> n;

    //a[0] = 1;
    a[1] = 1;
    a[2] = 1;
    a[3] = 2;
    for(int i=4;i<=n;i++){
        a[i] = a[i-1] + a[i-2];
    }
    //cout << a[n-1] << endl;

    cout << (a[n]+a[n-1])*2 + a[n]*2;
}