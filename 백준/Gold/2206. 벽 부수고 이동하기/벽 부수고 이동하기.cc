#include <iostream>
#include <queue>
using namespace std;

int n,m;
char board[1002][1002];
int visited[1002][1002][2];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void BFS(int x, int y){
    queue<pair<pair<int,int>,int>> Q;
    Q.push({{x,y},1});
    visited[x][y][1] = 1;
    while(!Q.empty()){
        int cur_x = Q.front().first.first;
        int cur_y = Q.front().first.second;
        int crash = Q.front().second;       // 1이면 한번 부술 수 있음, 0이면 더이상 부술 수 없음
        //cout << cur_x << " " << cur_y << endl;
        Q.pop();
        if(cur_x == n-1 && cur_y == m-1){
            cout << visited[cur_x][cur_y][crash];
            return;
        }
        for(int dir=0;dir<4;dir++){
            int nx = cur_x + dx[dir];
            int ny = cur_y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(visited[nx][ny][crash]) continue;
            if(board[nx][ny] == '1' && crash == 1){      // 벽을 만났고 부술 수 있으면
                visited[nx][ny][crash-1] = visited[cur_x][cur_y][crash] + 1;
                Q.push({{nx,ny},0});
            }
            else if(board[nx][ny] == '0' && !visited[nx][ny][crash]){
                visited[nx][ny][crash] = visited[cur_x][cur_y][crash] + 1;
                Q.push({{nx,ny},crash});
            }
        }
    }
    cout << -1;
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    char ch;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> ch;
            board[i][j] = ch;
        }
    }
    BFS(0,0);

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout << visited[i][j][0] << " ";
    //     }
    //     cout << endl;
    // }    
}