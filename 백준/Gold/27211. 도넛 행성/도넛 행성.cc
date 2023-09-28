#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;
#define X first
#define Y second

int n, m;
int board[1002][1002];
int visited[1002][1002];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void BFS(int x, int y){
    queue<pair<int,int>> Q;
    Q.push({x,y});
    visited[x][y] = 1;
    while(!Q.empty()){
        auto cur = Q.front();
        Q.pop();
        for(int dir=0;dir<4;dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0){
                nx = n-1;
            }
            if(nx >= n){
                nx = 0;
            }
            if(ny < 0){
                ny = m-1;
            }
            if(ny >= m){
                ny = 0;
            }
            if(visited[nx][ny] >= 2|| board[nx][ny] == 1) continue;
            visited[nx][ny]++;
            Q.push({nx,ny});
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cnt = 0;
    cin >> n >> m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> board[i][j];
        }
    }
    memset(visited, 0, sizeof(visited));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(visited[i][j] || board[i][j] == 1) continue;
            BFS(i,j);
            //cout << i << " " << j << endl;
            cnt++;
        }
    }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout << visited[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << cnt;
}