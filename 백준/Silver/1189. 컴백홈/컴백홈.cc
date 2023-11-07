#include <iostream>
using namespace std;

int R, C, K, cnt=0;
char board[7][7];
int visited[7][7];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void DFS(int cur_x, int cur_y, int dist){
    //cout << cur_x << " " << cur_y << endl;
    if(dist == K && cur_x == 0 && cur_y == C-1){
        cnt++;
        return;
    }
    for(int dir=0;dir<4;dir++){
        int nx = cur_x + dx[dir];
        int ny = cur_y + dy[dir];
        if(nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
        if(visited[nx][ny] || board[nx][ny] == 'T') continue;
        visited[nx][ny] = 1;
        DFS(nx,ny,dist+1);
        visited[nx][ny] = 0;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    char ch;
    cin >> R >> C >> K;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin >> ch;
            board[i][j] = ch;
        }
    }
    visited[R-1][0] = 1;
    DFS(R-1, 0, 1);
    cout << cnt;
}