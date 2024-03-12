#include <iostream>
#include <queue>
using namespace std;

int n,m;
char ch;
char board[502][502];
bool visited[502][502];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int max_area, cnt;

void Input(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> ch;
            board[i][j] = ch;
        }
    } 
}

int BFS(int a, int b){
    int area = 1;
    visited[a][b] = true;
    queue<pair<int,int>> Q;
    Q.push({a,b});
    while(!Q.empty()){
        int cur_x = Q.front().first;
        int cur_y = Q.front().second;
        //cout << cur_x << " " << cur_y << "\n";
        Q.pop();
        for(int dir=0;dir<4;dir++){
            int nx = cur_x + dx[dir];
            int ny = cur_y + dy[dir];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(visited[nx][ny] || board[nx][ny] == '0') continue;
            area++;
            Q.push({nx,ny});
            visited[nx][ny] = true;
        }
    }
    return area;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Input();
    max_area = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j] && board[i][j] == '1'){
                cnt++;
                int tmp = BFS(i,j);
                if(max_area < tmp){
                    max_area = tmp;
                }
            }
        }
    }

    cout << cnt << "\n" << max_area;
    

    return 0;
}