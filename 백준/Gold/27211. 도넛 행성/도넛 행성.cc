#include <iostream>
#include <queue>
using namespace std;

int N, M, cnt=0;
int board[1002][1002];
int visited[1002][1002];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void BFS(int x, int y){
    queue<pair<int,int>> Q;
    Q.push({x,y});
    while(!Q.empty()){
        int cur_x = Q.front().first;
        int cur_y = Q.front().second;
        //cout << cur_x << " " << cur_y << endl;
        Q.pop();
        for(int dir=0;dir<4;dir++){
            int nx = cur_x + dx[dir];
            int ny = cur_y + dy[dir];
            if(nx < 0){
                nx = N-1;
            }
            if(nx >= N){
                nx = 0;
            }
            if(ny < 0){
                ny = M-1;
            }
            if(ny >= M){
                ny = 0;
            }
            if(visited[nx][ny] || board[nx][ny] == 1) continue;
            Q.push({nx,ny});
            visited[nx][ny] = 1;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int num;
    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> num;
            board[i][j] = num;
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(visited[i][j] || board[i][j] == 1) continue;
            BFS(i,j);
            cnt++;
        }
    }
    cout << cnt;
}