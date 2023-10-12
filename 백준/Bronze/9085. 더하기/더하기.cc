#include <iostream>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, num,res=0;
        cin >> N;
        for(int i=0;i<N;i++){
            cin >> num;
            if(num <= 10){
                res += num;
            }
        }
        cout << res << "\n";
    }
    return 0;
}