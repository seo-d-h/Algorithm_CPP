#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

int N, K;
int visited[100002];
queue<int> Q;

void BFS(int start){
    Q.push(start);
    visited[start] = 0;
    while(!Q.empty()){
        int cur = Q.front();
        //cout << cur << " ";
        if(cur == K){
            cout << visited[cur];
            return;
        }
        Q.pop();
        for(auto i : {cur*2, cur-1, cur+1}){
            if(i < 0 || i > 100000) continue;
            if(visited[i] != 0) continue;
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
    cin >> N >> K;
    memset(visited, 0, sizeof(visited));
    BFS(N);
}