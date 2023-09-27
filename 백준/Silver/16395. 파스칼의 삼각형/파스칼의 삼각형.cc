#include <iostream>
#include <memory.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    long long pascal[32][32];
    cin >> n >> k;

    memset(pascal, 0, sizeof(pascal));

    pascal[1][1] = 1;
    pascal[2][1] = 1;
    pascal[2][2] = 1;

    for(int i=3;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j == 1 || j == i){
                pascal[i][j] = 1;
            }
            else{
                pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
            }
        }
    }

    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout << pascal[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << pascal[n][k];
}