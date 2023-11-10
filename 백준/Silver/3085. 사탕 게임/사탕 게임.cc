#include <iostream>
using namespace std;

int N;
char board[52][52];
int visited[52][52];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int count();

int change(int x, int y){
    int max_cnt = 0;
    for(int dir=0;dir<4;dir++){     // 4방향 확인
        int nx = x+dx[dir];
        int ny = y+dy[dir];
        if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
        swap(board[x][y], board[nx][ny]);       // 바꾸기
        
        int cnt = count();
        max_cnt = max(max_cnt, cnt);
        swap(board[x][y], board[nx][ny]);     // 원복
    }
    return max_cnt;
}

int count(){
    int max_cnt = 1;
    int cnt = 1;

    // for(int i=0;i<N;i++){
    //     for(int j=0;j<N;j++){
    //         cout << board[i][j];
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    for(int i=0;i<N;i++){       // 가로방향
        cnt = 1;
        for(int j=1;j<N;j++){
            if(board[i][j] == board[i][j-1]) cnt++;
            else cnt = 1;
            max_cnt = max(max_cnt, cnt);
        }
    }
    
    
    for(int i=0;i<N;i++){       // 세로방향
        cnt = 1;
        for(int j=1;j<N;j++){
            if(board[j][i] == board[j-1][i]) cnt++;
            else cnt = 1;
            max_cnt = max(max_cnt, cnt);
        }
    }
    
    return max_cnt;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cnt=0, max_cnt=0;
    char ch;
    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> ch;
            board[i][j] = ch;
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cnt = change(i,j);
            max_cnt = max(max_cnt, cnt);
        }
    }
    cout << max_cnt;
}