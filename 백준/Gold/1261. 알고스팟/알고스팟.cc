#include <iostream>
#include <queue>
#include <memory.h>
#include <limits.h>
using namespace std;

int N, M;       // M : 세로, N : 가로
char ch;
char board[102][102];
int dist[102][102];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
queue<pair<int,int>> Q;

void Input(){
    cin >> N >> M;
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            cin >> ch;
            board[i][j] = ch;
            dist[i][j] = 10000;
        }
    }
}

void BFS(int x, int y){
    Q.push({x,y});
    dist[x][y] = 0;
    while(!Q.empty()){
        int cur_x = Q.front().first;
        int cur_y = Q.front().second;
        Q.pop();
        //cout << cur_x << " " << cur_y << " " << dist[cur_x][cur_y] << endl;
        for(int dir=0;dir<4;dir++){
            int nx = cur_x + dx[dir];
            int ny = cur_y + dy[dir];
            if(nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
            if(board[nx][ny] == '1'){       // 벽
                if(dist[nx][ny] > dist[cur_x][cur_y]+1){
                    dist[nx][ny] = dist[cur_x][cur_y]+1;
                    Q.push({nx,ny});
                }
            }
            else if(board[nx][ny] == '0'){
                if(dist[nx][ny] > dist[cur_x][cur_y]){
                    dist[nx][ny] = dist[cur_x][cur_y];
                    Q.push({nx,ny});
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Input();
    BFS(0,0);

    cout << dist[M-1][N-1];
}