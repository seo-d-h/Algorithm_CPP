#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

int A, K;
queue<int> Q;
int dist[1000002];

void BFS(int start){
    Q.push(start);
    dist[start] = 0;
    while(!Q.empty()){
        int cur = Q.front();
        //cout << cur << " ";
        if(cur == K){
            cout << dist[cur];
            return;
        }
        Q.pop();
        for(auto i : {cur*2, cur+1}){
            if(i > 1000000) continue;
            if(dist[i] != -1) continue;
            dist[i] = dist[cur]+1;
            Q.push(i);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> A >> K;
    memset(dist, -1, sizeof(dist));
    BFS(A);
}