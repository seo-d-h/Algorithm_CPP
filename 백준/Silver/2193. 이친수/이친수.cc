#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    long long arr[92];
    arr[1] = 1;
    arr[2] = 1;
    cin >> N;
    for(int i=3;i<=N;i++){
        arr[i] = arr[i-1]+arr[i-2];
    }
    cout << arr[N];
}