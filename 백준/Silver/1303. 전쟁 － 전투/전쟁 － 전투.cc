#include <iostream>
#include <queue>
using namespace std;

int N, M;
char board[102][102];
int visited[102][102];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int BFS(int x, int y, char cur_ch){
    int cnt = 1;
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
            if(visited[nx][ny] || board[nx][ny] != cur_ch) continue;
            Q.push({nx,ny});
            visited[nx][ny] = 1;
            cnt++;
        }
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int w=0, b=0, tmp;
    char ch;
    cin >> M >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> ch;
            board[i][j] = ch;
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(visited[i][j]) continue;
            tmp = BFS(i,j,board[i][j]);
            //cout << "cnt : " << tmp << endl;
            if(board[i][j] == 'W'){
                w += tmp*tmp;
            }
            else if(board[i][j] == 'B'){
                b += tmp*tmp;
            }
        }
    }
    cout << w << " " << b;
}