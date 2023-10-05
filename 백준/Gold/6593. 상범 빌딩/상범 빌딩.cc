#include <iostream>
#include <queue>
#include <tuple>
#include <memory.h>
using namespace std;
#define X first
#define Y second
#define Z third

int l, r, c;
int dest_x, dest_y, dest_z;
char board[32][32][32];
int visited[32][32][32];
int dz[6] = {1,-1,0,0,0,0};
int dx[6] = {0,0,1,-1,0,0};
int dy[6] = {0,0,0,0,1,-1};



void BFS(int z, int x, int y){
    queue<tuple<int,int,int>> Q;
    Q.push({z,x,y});
    visited[z][x][y] = 1;
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int dir = 0;dir<6;dir++){
            int nz = get<0>(cur) + dz[dir];
            int nx = get<1>(cur) + dx[dir];
            int ny = get<2>(cur) + dy[dir];
            if(nx < 0 || nx >= r || ny < 0 || ny >= c || nz < 0 || nz >= l) continue;
            if(board[nz][nx][ny] == 'E'){
                cout << "Escaped in " << visited[get<0>(cur)][get<1>(cur)][get<2>(cur)]<< " minute(s).\n";
                for(int q = 0;q<Q.size();q++){
                    Q.pop();
                }
                return;
            }
            if(board[nz][nx][ny] == '#' || visited[nz][nx][ny] != 0) continue;
            visited[nz][nx][ny] = visited[get<0>(cur)][get<1>(cur)][get<2>(cur)]+1;
            Q.push({nz,nx,ny});
        }
    }
    cout << "Trapped!\n";
}

void fclear(){
    for(int i=0;i<l;i++){
        for(int j=0;j<r;j++){
            for(int k=0;k<c;k++){
                visited[i][j][k] = 0;
                board[i][j][k] = '0';       
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(1){
        // fill(&visited[0][0][0], &visited[32][32][32], 0);
        // fill(&board[0][0][0], &board[32][32][32], 0);
        memset(visited,0,sizeof(visited));
        memset(board,'0',sizeof(board));
        // fclear();
        char ch='0';
        int x=0,y=0,z=0;
        cin >> l >> r >> c;
        if(l == 0 && r == 0 && c == 0) return 0;
        for(int i=0;i<l;i++){
            for(int j=0;j<r;j++){
                for(int k=0;k<c;k++){
                    cin >> ch;
                    board[i][j][k] = ch;
                    if(ch == 'S'){
                        z = i;
                        x = j;
                        y = k;
                    }
                }
            }
        }
        BFS(z,x,y);
        // for(int i=0;i<l;i++){
        //     for(int j=0;j<r;j++){
        //         for(int k=0;k<c;k++){
        //             cout << visited[i][j][k];
        //         }
        //     }
        //     cout << endl;
        // }
    }
}