#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

int n, m;
int island = 1;
int board[302][302];
int reduce_board[302][302];
int visited[302][302];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void BFS(int x, int y){
    queue<pair<int,int>> Q;
    Q.push({x,y});
    visited[x][y] = 1;
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        int cur_x = cur.first;
        int cur_y = cur.second;
        
        int cnt = 0;
        for(int dir=0;dir<4;dir++){
            int nx = cur_x + dx[dir];
            int ny = cur_y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(board[cur_x][cur_y] != 0 && board[nx][ny] == 0){       // 현재 위치가 섬일때
                //cout << cur_x << " " << cur_y << " : " << board[cur_x][cur_y]<<endl;
                reduce_board[cur_x][cur_y]++;
            }
            if(!visited[nx][ny]){
                visited[nx][ny] = 1;
                Q.push({nx,ny});
            }
        }
    }
}

void cnt_island(int x, int y){
    queue<pair<int,int>> Q;
    Q.push({x,y});
    visited[x][y] = 1;
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int dir=0;dir<4;dir++){
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(visited[nx][ny] || board[nx][ny] == 0) continue;
            visited[nx][ny] = 1;
            Q.push({nx,ny});
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int res = 0;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> board[i][j];
        }
    }

    while(island != 0){
        memset(visited, 0, sizeof(visited));
        memset(reduce_board, 0, sizeof(reduce_board));
        BFS(0,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                board[i][j] = max(0, board[i][j] - reduce_board[i][j]);
            }
        }
   
        memset(visited, 0, sizeof(visited));
        int cnt_0 = 0;
        island = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] != 0 && visited[i][j] == 0){
                    cnt_island(i,j);
                    island++;
                }
            }
        }

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout << board[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;

        if(island == 0){
            cout << 0;
            return 0;
        }
        res++;
        if(island >= 2) break;
    }


    cout << res;

    return 0;
}