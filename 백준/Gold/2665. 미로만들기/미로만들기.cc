#include <iostream>
#include <queue>
using namespace std;
#define MAX 987654321

int n;
char ch;
char board[52][52];
int dist[52][52];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};
queue<pair<int,int>> Q;

void Input(){
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> ch;
            board[i][j] = ch;
            dist[i][j] = MAX;
        }
    }
}

void BFS(){
    Q.push({0,0});
    dist[0][0] = 0;
    while(!Q.empty()){
        int cur_x = Q.front().first;
        int cur_y = Q.front().second;
        Q.pop();
        for(int dir=0;dir<4;dir++){
            int nx = cur_x + dx[dir];
            int ny = cur_y + dy[dir];
            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if(board[nx][ny] == '1'){       // 빈방
                if(dist[nx][ny] > dist[cur_x][cur_y]){
                    dist[nx][ny] = dist[cur_x][cur_y];
                    Q.push({nx,ny});
                }
            }
            else{       // 벽
                if(dist[nx][ny] > dist[cur_x][cur_y]+1){
                    dist[nx][ny] = dist[cur_x][cur_y]+1;
                    //cout << nx << " " << ny << endl;
                    Q.push({nx,ny});
                }
            }
        }
    }
}

void Output(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Input();
    BFS();
    //Output();
    cout << dist[n-1][n-1];

    return 0;
}