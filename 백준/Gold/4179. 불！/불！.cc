#include <iostream>
#include <queue>
using namespace std;
#define X first
#define Y second

int r,c;
int jx, jy;
char board[1002][1002] = {0};
int jvisited[1002][1002] = {0};
int fvisited[1002][1002] = {0};
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
queue<pair<int,int>> JQ;
queue<pair<int,int>> FQ;
 
void BFS(int x, int y){
    while(!JQ.empty()){
        int fq_size = FQ.size();
        for(int i=0;i<fq_size;i++){
            pair<int,int> fcur = FQ.front(); FQ.pop();
            //cout << "f : " << fcur.X << " " << fcur.Y << endl;
            for(int fdir=0;fdir<4;fdir++){
                int nx = fcur.X + dx[fdir];
                int ny = fcur.Y + dy[fdir];
                if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                if(fvisited[nx][ny]) continue;
                if(board[nx][ny] == '#') continue;
                board[nx][ny] = 'F';
                fvisited[nx][ny] = 1;
                FQ.push({nx,ny});
            }
        }

        pair<int,int> jcur = JQ.front(); JQ.pop();
        //cout << "j : " << jcur.X << " " << jcur.Y << endl;
        for(int jdir=0;jdir<4;jdir++){
            int nx = jcur.X + dx[jdir];
            int ny = jcur.Y + dy[jdir];
            if(nx < 0 || nx >= r || ny < 0 || ny >= c){
                cout << jvisited[jcur.X][jcur.Y];
                return;
            }
            if(fvisited[nx][ny]) continue;
            if(board[nx][ny] == '#' || board[nx][ny] == 'F') continue;
            jvisited[nx][ny] = jvisited[jcur.X][jcur.Y] + 1;
            JQ.push({nx,ny});
        }

        
    }

    // for(int i=0;i<r;i++){
    //     if(jvisited[i][0] != 0){
    //         min_dist = min(min_dist, jvisited[i][0]);
    //     }
    //     if(jvisited[i][c-1] != 0){
    //         min_dist = min(min_dist, jvisited[i][c-1]);
    //     }
    // }
    // for(int j=0;j<c;j++){
    //     if(jvisited[0][j] != 0){
    //         min_dist = min(min_dist,jvisited[0][j]);
    //     }
    //     if(jvisited[r-1][j] != 0){
    //         min_dist = min(min_dist,jvisited[r-1][j]);
    //     }
    // }

    cout << "IMPOSSIBLE";
    //else   cout << min_dist;
    
}

void FBFS(){
    while(!FQ.empty()){
    int fq_size = FQ.size();
        for(int i=0;i<fq_size;i++){
            pair<int,int> fcur = FQ.front(); FQ.pop();
            //cout << "f : " << fcur.X << " " << fcur.Y << endl;
            for(int fdir=0;fdir<4;fdir++){
                int nx = fcur.X + dx[fdir];
                int ny = fcur.Y + dy[fdir];
                if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
                if(fvisited[nx][ny]) continue;
                if(board[nx][ny] == '#') continue;
                fvisited[nx][ny] = fvisited[fcur.X][fcur.Y]+1;
                FQ.push({nx,ny});
            }
        }
    }
    // for(int i=0;i<r;i++){
    //     for(int j=0;j<c;j++){
    //         cout << fvisited[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}

void JBFS(){
    while(!JQ.empty()){
        pair<int,int> jcur = JQ.front(); JQ.pop();
        //cout << "j : " << jcur.X << " " << jcur.Y << endl;
        for(int jdir=0;jdir<4;jdir++){
            int nx = jcur.X + dx[jdir];
            int ny = jcur.Y + dy[jdir];
            if(nx < 0 || nx >= r || ny < 0 || ny >= c){
                cout << jvisited[jcur.X][jcur.Y];
                return;
            }
            if(jvisited[nx][ny]) continue;
            if(fvisited[nx][ny] && fvisited[nx][ny] <= jvisited[jcur.X][jcur.Y]+1) continue;
            if(board[nx][ny] == '#') continue;
            jvisited[nx][ny] = jvisited[jcur.X][jcur.Y] + 1;
            JQ.push({nx,ny});
        }
    }

    // for(int i=0;i<r;i++){
    //     for(int j=0;j<c;j++){
    //         cout << jvisited[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << "IMPOSSIBLE";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    char ch;
    cin >> r >> c;

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> ch;
            board[i][j] = ch;
            if(ch == 'J'){
                jx = i;
                jy = j;
                JQ.push({jx,jy});
                jvisited[jx][jy] = 1;
            }
            if(ch == 'F'){
                FQ.push({i,j});
                fvisited[i][j] = 1;
            }
        }
    }
    FBFS();
    JBFS();
    //BFS(jx,jy);

    

}