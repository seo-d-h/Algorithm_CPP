#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>
using namespace std;

int n, m, r;
int u, v;
vector<int> vec[100002];
int visited[100002];
int dist=1;

void BFS(int start){
    visited[start] = dist;
    dist++;
    queue<int> Q;
    Q.push(start);
    while(!Q.empty()){
        int cur = Q.front();
        Q.pop();
        for(int i=0;i<vec[cur].size();i++){
            if(visited[vec[cur][i]]) continue;
            visited[vec[cur][i]] = dist;
            dist++;
            Q.push(vec[cur][i]);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> r;
    for(int i=0;i<m;i++){
        cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        sort(vec[i].begin(), vec[i].end(), greater<>());
    }
    memset(visited, 0, sizeof(visited));
    BFS(r);
    for(int i=1;i<=n;i++){
        cout << visited[i] << "\n";
    }
}