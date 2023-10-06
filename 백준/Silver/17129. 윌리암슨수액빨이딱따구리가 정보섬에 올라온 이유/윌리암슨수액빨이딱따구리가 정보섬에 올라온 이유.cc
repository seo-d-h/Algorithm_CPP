#include <iostream>
#include <queue>
using namespace std;

int n, m;
char board[3002][3002];
bool visited[3002][3002];
int dist[3002][3002];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
queue<pair<int,int>> Q;


void BFS(){
    while(!Q.empty()){
        int cur_x = Q.front().first;
        int cur_y = Q.front().second;
        if(board[cur_x][cur_y] == '3' || board[cur_x][cur_y] == '4' || board[cur_x][cur_y] == '5'){
            cout << "TAK\n"; 
            cout << dist[cur_x][cur_y];
            return;
        }
        Q.pop();
        for(int dir=0;dir<4;dir++){
            int nx = cur_x + dx[dir];
            int ny = cur_y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(visited[nx][ny] || board[nx][ny] == '1') continue;
            visited[nx][ny] = true;
            dist[nx][ny] = dist[cur_x][cur_y] + 1;
            Q.push({nx,ny});
        }
    }
    cout << "NIE";
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
            if(ch == '2'){
                Q.push({i,j});
                visited[i][j] = true;
            }
        }
    }
    BFS();
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout << dist[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}