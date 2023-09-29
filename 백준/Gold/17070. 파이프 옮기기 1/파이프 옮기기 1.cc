#include <iostream>
#include <queue>
using namespace std;

int n;
int cnt = 0;
int board[18][18];
int visited[18][18];
int dx[3] = {0,1,1};
int dy[3] = {1,0,1};

void DFS(int x, int y, int state){      // state가 0이면 가로방향으로 확장, 1이면 세로, 2면 대각선
    //cout << "x : " << x << ", y : " << y << endl;
    if(x == n-1 && y == n-1){
        cnt++;
        return;
    }
    else{
        for(int dir=0;dir<3;dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if((state == 0 && dir == 1) || (state == 1 && dir == 0)) continue;
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(visited[nx][ny] || board[nx][ny]) continue;
            if(dir == 2 && (board[x][ny] == 1 || board[nx][y] == 1 || board[nx][ny] == 1)) continue;
            visited[nx][ny] = 1;
            DFS(nx, ny, dir);
            visited[nx][ny] = 0;
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
    DFS(0,1,0);
    cout << cnt;
}