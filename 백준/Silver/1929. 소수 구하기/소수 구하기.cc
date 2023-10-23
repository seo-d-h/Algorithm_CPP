#include <iostream>
using namespace std;

int arr[1000002];

int main(){
    int M, N;
    
    cin >> M >> N;
    for(int i=M;i<=N;i++){
        arr[i] = i;
    }

    arr[1] = 0; 
    for(int i=2;i<=N;i++){
        for(int j=i*2;j<=N;j+=i){
            //cout << j << endl;
            arr[j] = 0;
        }
    }

    for(int i=M;i<=N;i++){
        if(arr[i] != 0) cout << arr[i] << "\n";
    }

}