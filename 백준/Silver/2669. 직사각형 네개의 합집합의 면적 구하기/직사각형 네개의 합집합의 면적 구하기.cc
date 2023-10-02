#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int x1,y1,x2,y2;
    int trial = 4;
    int visited[102][102];
    int res=0;
    
    while(trial--){
        cin >> x1 >> y1 >> x2 >> y2;
        for(int i=x1;i<x2;i++){
            for(int j=y1;j<y2;j++){
                if(visited[i][j]) continue;
                visited[i][j] = 1;
                res++;
            }
        }
    }
    cout << res;
}