#include <iostream>
#include <queue>
using namespace std;

int N, M, res=0;
int board[102][72];
bool visited[102][72];
int dx[8] = {-1,0,1,1,1,0,-1,-1};
int dy[8] = {-1,-1,-1,0,1,1,1,0};
bool top;

void Input(){
    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> board[i][j];
        }
    }
}

void BFS(int x, int y){
    visited[x][y] = 1;
    queue<pair<int,int>> Q;
    Q.push({x,y});
    while(!Q.empty()){
        int cur_x = Q.front().first;
        int cur_y = Q.front().second;
        //cout << cur_x << " " << cur_y << endl;
        Q.pop();
        for(int dir=0;dir<8;dir++){
            int nx = cur_x + dx[dir];
            int ny = cur_y + dy[dir];
            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if(board[x][y] < board[nx][ny]) top = false;
            if(visited[nx][ny] || board[x][y] != board[nx][ny]) continue;
            visited[nx][ny] = 1;
            Q.push({nx, ny});
        }
    }
}

void Solution(){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(!visited[i][j] && board[i][j]){
                //cout << "i, j : " << i << " " << j << endl;
                top = true; 
                BFS(i,j);
                if(top) res++;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Input();
    Solution();
    cout << res;
}