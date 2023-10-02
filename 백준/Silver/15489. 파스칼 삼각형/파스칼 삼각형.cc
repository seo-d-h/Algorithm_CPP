#include <iostream>
#include <memory.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int r, c, w;
    long long pascal[32][32];
    long long res = 0;
    memset(pascal, 0, sizeof(pascal));
    pascal[1][1] = 1;
    pascal[2][1] = 1;
    pascal[2][2] = 1;
    
    cin >> r >> c >> w;
    for(int i=3;i<r+w;i++){
        for(int j=1;j<r+w;j++){
            if(j==1 || j==i){
                pascal[i][j] = 1;
                continue;
            }
            else{
                pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
            }
        }
    }
    // for(int i=1;i<r+w;i++){
    //     for(int j=1;j<r+w;j++){
    //         cout << pascal[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    for(int i=0;i<=w;i++){
        for(int j=0;j<=i;j++){
            res += pascal[r+i][c+j];
        }
    }
    
    cout << res;
}