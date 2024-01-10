#include <iostream>
#include <queue>
#include <limits.h>
using namespace std;

int T=0, N, rupee;
int board[127][127];
int cost[127][127];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};

void BFS(){
    queue<pair<int,int>> Q;
    Q.push({0,0});
    cost[0][0] = board[0][0];
    while(!Q.empty()){
        int cur_x = Q.front().first;
        int cur_y = Q.front().second;
        Q.pop();
        for(int dir=0;dir<4;dir++){
            int nx = cur_x + dx[dir];
            int ny = cur_y + dy[dir];
            if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if(cost[nx][ny] > cost[cur_x][cur_y]+board[nx][ny]){
                cost[nx][ny] = cost[cur_x][cur_y]+board[nx][ny];
                Q.push({nx,ny});
            }
        }
    }
}

void Solution(){
    while(++T){
        cin >> N;
        if(N==0) return;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cin >> rupee;
                board[i][j] = rupee;
                cost[i][j] = INT_MAX;
            }
        }
        BFS();
        cout << "Problem " << T << ": " << cost[N-1][N-1] << "\n";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Solution();

    return 0;
}