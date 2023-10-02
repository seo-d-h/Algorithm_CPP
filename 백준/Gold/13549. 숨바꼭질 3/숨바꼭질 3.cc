#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

int n, k;
int board[100002];
int visited[100002];

void BFS(int start){
    queue<int> Q;
    Q.push(start);
    visited[start] = 0;
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        if(cur == k){
            cout << visited[k];
            return;
        }
        //cout << cur << endl;
        for(int i : {cur*2, cur-1, cur+1}){
            //cout << board[i] << " ";
            if(i < 0 || i >= 100002) continue;
            if(visited[i] != -1) continue;
            if(i == cur*2){
                visited[i] = visited[cur];
            }
            else{
                visited[i] = visited[cur]+1;
            }
            Q.push(i);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    memset(board,0,sizeof(board));
    memset(visited, -1, sizeof(visited));
    //board[n] = 1;
    
    board[k] = 2;
    
    
    BFS(n);
    // for(int i=0;i<=100;i++){
    //     cout << visited[i] << " ";
    // }
    // cout << endl;
    //cout << visited[k];
}