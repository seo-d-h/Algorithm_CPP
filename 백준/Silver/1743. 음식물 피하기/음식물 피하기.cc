#include <iostream>
#include <queue>
using namespace std;

int N, M, K;
int board[102][102];
int visited[102][102];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int BFS(int x, int y){
    int area = 1;
    queue<pair<int,int>> Q;
    Q.push({x,y});
    visited[x][y] = 1;
    while(!Q.empty()){
        int cur_x = Q.front().first;
        int cur_y = Q.front().second;
        Q.pop();
        for(int dir=0;dir<4;dir++){
            int nx = cur_x + dx[dir];
            int ny = cur_y + dy[dir];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(visited[nx][ny] || board[nx][ny] == 0) continue;
            Q.push({nx,ny});
            visited[nx][ny] = 1;
            area++;
        }
    }
    return area;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int a, b, max_area=0;
    cin >> N >> M >> K;

    for(int i=0;i<K;i++){
        cin >> a >> b;
        board[a-1][b-1] = 1;
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(visited[i][j] || board[i][j] == 0) continue;
            int area = BFS(i,j);
            max_area = max(max_area, area);
        }
    }
    cout << max_area;
}