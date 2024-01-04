#include <iostream>
#include <limits.h>
using namespace std;

int N;
int arr[12];
int op[4];
int maxi = INT_MIN;
int mini = INT_MAX;

void DFS(int depth, int res){
    if(depth == N){
        maxi = max(maxi, res);
        mini = min(mini, res);
    }
    for(int i=0;i<4;i++){
        if(op[i]){
            op[i]--;
            if(i==0){       // 더하기
                DFS(depth+1, res+arr[depth]);
            }
            else if(i==1){      // 빼기
                DFS(depth+1, res-arr[depth]);
            }
            else if(i==2){      // 곱하기
                DFS(depth+1, res*arr[depth]);
            }
            else{       // 나누기
                DFS(depth+1, res/arr[depth]);
            }
            op[i]++;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    for(int i=0;i<4;i++){
        cin >> op[i];
    }
    DFS(1,arr[0]);
    cout << maxi << "\n" << mini;
}