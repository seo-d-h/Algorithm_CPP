#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int P;
    cin >> P;
    while(P--){
        int num = 0;
        int res = 0;
        int arr[22];
        int tmp = 0;
        cin >> num;
        for(int j=0;j<20;j++){
            cin >> arr[j];
        }
        for(int j=0;j<20;j++){
            for(int k=j;k<20;k++){
                if(arr[j] > arr[k]){
                    res++;
                }
            }
        }
        cout << num << " " << res << "\n";
    }
}