#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    int s[302];
    int a[302];
    cin >> n;

    for(int i=0;i<n;i++){
        cin >> s[i];
    }

    a[0] = s[0];
    a[1] = s[0] + s[1];
    a[2] = max(s[0] + s[2], s[1]+s[2]);

    for(int i=3;i<n;i++){
        a[i] = max(a[i-3]+s[i-1]+s[i], a[i-2]+s[i]);
        //cout << "i : " << a[i]<<endl;
    }
    cout << a[n-1];
}