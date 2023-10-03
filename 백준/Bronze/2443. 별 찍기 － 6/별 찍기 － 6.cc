#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            cout << ' ';
        }
        for(int j=i;j<2*n-i-1;j++){
            cout << "*";
        }
        cout << "\n";
    }
}