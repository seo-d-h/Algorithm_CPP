#include <iostream>
#include <vector>
using namespace std;

char ch;
int N, K, res=0;
char arr[20002];
bool flag=0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    for(int i=0;i<N;i++){
        cin >> ch;
        arr[i] = ch;
    }
    for(int i=0;i<N;i++){
        if(arr[i] == 'P'){
            for(int j=K;j>=1;j--){
                if(arr[i-j] == 'H'){
                    arr[i-j] = 'h';
                    //cout << i-j << " ";
                    res++;
                    flag = 1;
                    break;
                }
            }
            for(int j=1;j<=K;j++){
                if(flag){
                    flag = 0;
                    break;
                }
                if(arr[i+j] == 'H'){
                arr[i+j] = 'h';
                //cout << i+j << ' ';
                res++;
                break;
                }
            }
        }
        // for(int j=0;j<N;j++){
        //     cout << arr[j] << " ";
        // }
        // cout << "\n";
    }
    cout << res;
}