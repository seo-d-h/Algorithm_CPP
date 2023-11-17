#include <iostream>
#include <queue>
using namespace std;
#define X first
#define Y second

int n,m, maxi=0;
int board[52][52];
int visited[52][52];
int dx[8] = {1,1,0,-1,-1,-1,0,1};
int dy[8] = {0,1,1,1,0,-1,-1,-1};

queue<pair<int,int>> Q;

void BFS(){
    while(!Q.empty()){
        pair<int,int> cur = Q.front(); Q.pop();
        for(int i=0;i<8;i++){
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(visited[nx][ny]) continue;
            visited[nx][ny] = visited[cur.X][cur.Y] + 1;
            maxi = max(maxi, visited[nx][ny]);
            Q.push({nx,ny});
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> board[i][j];
            if(board[i][j] == 1){
                Q.push({i,j});
                visited[i][j] = 1;
            }
        }
    }
    BFS();
    cout << maxi-1;
}