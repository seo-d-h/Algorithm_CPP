#include <iostream>
#include <queue>
using namespace std;

int N, M, K;
char ch;
int board[1002][1002];
int dist[1002][1002][12];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};

void Input(){
    cin >> N >> M >> K;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> ch;
            board[i][j] = ch-'0';
        }
    }
}

void Output(){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cout << dist[i][j][1] << " ";
        }
        cout << endl;
    }
}

void BFS(int cnt){
    queue<pair<pair<int,int>,int>> Q;   // x, y, 벽
    Q.push({{0,0},0});
    dist[0][0][0] = 1;
    while(!Q.empty()){
        int cur_x = Q.front().first.first;
        int cur_y = Q.front().first.second;
        int crash = Q.front().second;
        if(cur_x == N-1 && cur_y == M-1){
            cout << dist[cur_x][cur_y][crash];
            return;
        }
        Q.pop();
        for(int dir=0;dir<4;dir++){
            int nx = cur_x + dx[dir];
            int ny = cur_y + dy[dir];
            //cout << nx << " " << ny << " " << crash << endl;
            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if(dist[nx][ny][crash]) continue;
            if(!board[nx][ny] && !dist[nx][ny][crash]){        // 다음 위치가 공백이고 방문한적이 없으면
                dist[nx][ny][crash] = dist[cur_x][cur_y][crash]+1;
                Q.push({{nx,ny},crash});
            }
            else if(board[nx][ny] && crash < cnt && !dist[nx][ny][crash+1]){        // 다음 위치가 벽이고 부술 수 있으면
                dist[nx][ny][crash+1] = dist[cur_x][cur_y][crash]+1;
                Q.push({{nx,ny}, crash+1});
            }
        }
    }
    cout << -1;
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Input();
    BFS(K);
    //Output();
    
    return 0;
}