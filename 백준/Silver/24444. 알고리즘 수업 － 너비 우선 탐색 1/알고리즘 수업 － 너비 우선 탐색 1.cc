#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>
#include <algorithm>
using namespace std;

int n, m, r;
vector<int> graph[100002];
int visited[100002];
int result[100002];
int cnt = 0;

void BFS(int start){
    queue<int> Q;
    cnt++;
    visited[start] = 1;
    result[start] = cnt;
    Q.push(start);
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        //cout << "cur :" << cur << endl;
        for(int i=0;i<graph[cur].size();i++){
            if(visited[graph[cur][i]]) continue;
            cnt++;
            //cout << "idx : " << graph[cur][i] << endl;
            result[graph[cur][i]] = cnt;
            visited[graph[cur][i]] = 1;
            Q.push(graph[cur][i]);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a,b;
    cin >> n >> m >> r;

    for(int i=0;i<m;i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i=1;i<=n;i++){
        sort(graph[i].begin(), graph[i].end());
    }


    BFS(r);

    for(int i=1;i<=n;i++){
        cout << result[i] << "\n";
    }
}