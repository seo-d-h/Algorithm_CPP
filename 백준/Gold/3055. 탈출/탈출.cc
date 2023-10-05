#include<iostream>
#include <queue>
using namespace std;
#define X first
#define Y second
#define MAX 52

bool flag = 0;
int r,c;
char board[MAX][MAX];
int water_dist[MAX][MAX];
int kaktus_dist[MAX][MAX];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
queue<pair<int,int>> water_Q;
queue<pair<int,int>> kaktus_Q;

void Init(){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            water_dist[i][j] = -1;
            kaktus_dist[i][j] = -1;
        }
    }
}

void water_BFS(){
    while(!kaktus_Q.empty()){
        int water_size = water_Q.size();
        for(int dir = 0;dir<water_size;dir++){
            auto cur = water_Q.front(); water_Q.pop();
            //cout << cur.X << " " << cur.Y << endl;
            for(int i = 0;i<4;i++){     // 물 1회 이동
                int nx = cur.X + dx[i];
                int ny = cur.Y + dy[i];
                if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                if(water_dist[nx][ny] != -1) continue;
                //if(board[nx][ny] == 'X'||board[nx][ny]=='D'||board[nx][ny] == 'S') continue; 
                if(board[nx][ny] == '.'){
                    water_dist[nx][ny] = water_dist[cur.X][cur.Y] + 1;
                    board[nx][ny] = '*';
                    water_Q.push({nx,ny});
                }
            }
        }
        // cout << "water" << endl;
        // for(int i=0;i<r;i++){
        //     for(int j=0;j<c;j++){
        //         cout << board[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        int kaktus_size = kaktus_Q.size();
        for(int dir=0;dir<kaktus_size;dir++){
            auto kak_cur = kaktus_Q.front(); kaktus_Q.pop();
            for(int i=0;i<4;i++){
                int nx = kak_cur.X + dx[i];
                int ny = kak_cur.Y + dy[i];
                if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                if(kaktus_dist[nx][ny] != -1) continue;
                //if(board[nx][ny] == 'X' || board[nx][ny] == '*') continue;
                if(board[nx][ny] == '.' || board[nx][ny] == 'D'){
                    kaktus_dist[nx][ny] = kaktus_dist[kak_cur.X][kak_cur.Y] + 1;
                    board[nx][ny] = 'S';
                    kaktus_Q.push({nx,ny});
                }
            }
        }
        
        // cout << "kaktus" << endl;
        // for(int i=0;i<r;i++){
        //     for(int j=0;j<c;j++){
        //         cout << board[i][j] << " ";
        //     }
        //     cout << endl;
        // }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    char a;
    int water_x,water_y;
    int kak_x,kak_y;
    int goal_x,goal_y;
    cin >> r >> c;
    Init();
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> a;
            board[i][j] = a;
            if(a == '*'){       // 물이면
                water_Q.push({i,j});
                water_dist[i][j] = 0;
            }
            if(a == 'S'){       // 고슴도치이면
                kaktus_Q.push({i,j});
                kaktus_dist[i][j] = 0;
            }
            if(a == 'D'){       // 비버 집 위치 저장
                goal_x = i;
                goal_y = j;
            }
        }
    }

    water_BFS();
    //kaktus_BFS();

    
   
    
    if(flag){
        cout << kaktus_dist[goal_x][goal_y];
    }
    else{
        for(int i=0;i<4;i++){                // 목적지 인접4방향 판단
            int nx = goal_x + dx[i];
            int ny = goal_y + dy[i];
            if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if(water_dist[nx][ny] > 0 && water_dist[nx][ny] <= kaktus_dist[nx][ny]) continue;
            if(kaktus_dist[nx][ny] == -1) continue;
            cout << kaktus_dist[goal_x][goal_y];
            return 0;
        }
        cout << "KAKTUS";
        return 0;
    }
}