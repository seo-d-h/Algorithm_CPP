#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>
#include <limits.h>
using namespace std;

int N, M;
vector<int> vec[10002];
vector<int> res;
int visited[10002];

int BFS(int x){
    int dist = 1;
    visited[x] = 1;
    queue<int> Q;
    Q.push(x);
    while(!Q.empty()){
        int cur = Q.front();
        Q.pop();
        for(int i=0;i<vec[cur].size();i++){
            if(visited[vec[cur][i]]) continue;
            dist++;
            visited[vec[cur][i]] = 1;
            Q.push(vec[cur][i]);
        }
    }
    return dist;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int a, b;
    cin >> N >> M;
    int arr[10002], maxi = 0;
    for(int i=0;i<M;i++){
        cin >> a >> b;
        vec[b].push_back(a);
    }

    for(int i=1;i<=N;i++){
        memset(visited, 0, sizeof(visited));
        int dist = BFS(i);
        arr[i] = dist;
        maxi = max(maxi, dist);
    }

    for(int i=1;i<=N;i++){
        if(arr[i] == maxi) cout << i << " ";
    }
}