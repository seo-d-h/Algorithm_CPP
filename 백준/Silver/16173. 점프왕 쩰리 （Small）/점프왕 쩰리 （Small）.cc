#include <iostream>
#include <queue>
using namespace std;

int n;
int board[5][5];
int visited[5][5];
int dx[4] = {1,0};
int dy[4] = {0,1};

void BFS(int x, int y){
    queue<pair<int,int>> Q;
    Q.push({x,y});
    visited[x][y] = 1;
    while(!Q.empty()){
        int cur_x = Q.front().first;
        int cur_y = Q.front().second;
        Q.pop();
        for(int dir=0;dir<2;dir++){
            int nx = cur_x + dx[dir]*board[cur_x][cur_y];
            int ny = cur_y + dy[dir]*board[cur_x][cur_y];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(visited[nx][ny]) continue;
            visited[nx][ny] = 1;
            Q.push({nx,ny});
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> board[i][j];
        }
    }
    BFS(0,0);
    if(visited[n-1][n-1]) cout << "HaruHaru";
    else cout << "Hing";
}