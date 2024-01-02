#include <iostream>
#include <queue>
using namespace std;

int main(){
    int n, m;
    string board[102];
    int dist[102][102];
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    queue<pair<int,int>> Q;

    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> board[i];
    }

    Q.push({0,0});

    while(!Q.empty()){
        pair<int,int> cur = Q.front(); Q.pop();
        for(int i=0;i<4;i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(dist[nx][ny] > 0 || board[nx][ny] != '1') continue;
            dist[nx][ny] = dist[cur.first][cur.second]+1;
            Q.push({nx, ny});
        }
    }
    cout << dist[n-1][m-1]+1;

}