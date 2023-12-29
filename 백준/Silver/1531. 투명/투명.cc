#include <iostream>
#include <memory.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,m;
    int x1, x2, y1, y2;
    int res=0;
    int table[101][101];

    memset(table, 0, sizeof(table));
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> x1 >> y1 >> x2 >> y2;
        for(int x=x1;x<=x2;x++){
            for(int y=y1;y<=y2;y++){
                table[x][y]++;
            }
        }
    }


    for(int i=0;i<=100;i++){
        for(int j=0;j<=100;j++){
            if(table[i][j] > m){
                res++;
            }
        }
    }
    cout << res;
}