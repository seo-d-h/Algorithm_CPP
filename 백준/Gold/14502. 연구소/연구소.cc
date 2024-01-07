#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

int N, M, res=0;
int cnt_clean=0;
int board[10][10];
int cpy_board[10][10];
int visited[10][10];
int wall_visited[10][10];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void board_cpy(){
    memset(cpy_board, 0, sizeof(cpy_board));
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cpy_board[i][j] = board[i][j];
        }
    }
}

void BFS(){
    queue<pair<int,int>> Q;
    board_cpy();
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(cpy_board[i][j] == 2){
                Q.push({i,j});
                visited[i][j]=1;
            }
        }
        
    }
    while(!Q.empty()){
        int cur_x = Q.front().first;
        int cur_y = Q.front().second;
        Q.pop();
        for(int dir=0;dir<4;dir++){
            int nx = cur_x + dx[dir];
            int ny = cur_y + dy[dir];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(!cpy_board[nx][ny] && !visited[nx][ny]){
                visited[nx][ny] = 1;
                cpy_board[nx][ny] = 2;
                Q.push({nx,ny});
            }
        }
    }
    int cnt_clean = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            //cout << cpy_board[i][j] << " ";
            if(cpy_board[i][j] == 0){
                cnt_clean++;
            }
        }
        //cout << endl;
    }
    //cout << endl;
    res = max(res, cnt_clean);
}

void wall(int cnt){     // 벽 설치
    if(cnt == 3){       // BFS실행
        BFS();
        memset(visited, 0, sizeof(visited));
        return;
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(board[i][j]) continue;
            board[i][j] = 1;
            wall(cnt+1);
            board[i][j] = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> board[i][j];
        }
    }
    wall(0);
    cout << res;
}