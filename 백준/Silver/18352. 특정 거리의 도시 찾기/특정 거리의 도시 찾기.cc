#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, k, x;
vector<int> board[300002];
queue<int> Q;
int visited[300002] = {0,};
int dist[300002] = {0,};

void BFS(int start){
    Q.push(start);
    visited[start] = 1;
    while(!Q.empty()){
        int cur = Q.front();
        Q.pop();
        for(int i=0;i<board[cur].size();i++){
            if(visited[board[cur][i]]) continue;
            //cout << board[cur][i] << endl;
            visited[board[cur][i]] = 1;
            dist[board[cur][i]] = dist[cur]+1;
            Q.push(board[cur][i]);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int a, b;
    cin >> n >> m >> k >> x;
    for(int i=0;i<m;i++){
        cin >> a >> b;
        board[a].push_back(b);
        if(a == x){
            visited[b] = 1;
            dist[b] = 1;
            Q.push(b);
        }
    }

    BFS(x);
    vector<int> vec;
    for(int i=1;i<=n;i++){
        //cout << dist[i] << " ";
        if(dist[i] == k) vec.push_back(i);
    }
    sort(vec.begin(), vec.end());

    if(vec.empty()){
        cout << -1;
    }
    else{
        for(auto res : vec){
            cout << res << "\n";
        }
    }
    
}