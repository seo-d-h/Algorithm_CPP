#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>
using namespace std;

int n, m;
vector<pair<int,int>> board[1002];
int visited[1002];
pair<int,int> p;

void DFS(int current, int goal, int cnt){
    if(current == goal){
        cout << cnt << "\n";
        return;
    }
    if(visited[current]) return;
    //cout << "current : " << current << endl;
    visited[current] = 1;

    for(auto a : board[current]){
        DFS(a.first, goal, cnt+a.second);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a=0, b=0, dist=0;
    cin >> n >> m;

    for(int i=0;i<n-1;i++){
        cin >> a >> b >> dist;
        board[a].push_back({b,dist});
        board[b].push_back({a,dist});
    }

    // for(int i=1;i<=n;i++){
    //     cout << board[i].front().first << " " << board[i].front().second << endl;
    // }

    for(int i=0;i<m;i++){
        cin >> a >> b;
        memset(visited, 0, sizeof(visited));
        DFS(a,b,0);
    }
}