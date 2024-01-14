#include <iostream>
using namespace std;

int R, C;
char board[102][102];
char mine[102][102];
bool flag = 0;
int dx[8] = {-1,0,1,1,1,0,-1,-1};
int dy[8] = {-1,-1,-1,0,1,1,1,0};

void Reset(){
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            board[i][j] = 0;
            mine[i][j] = '0';
        }
    }
}

void Solution(){
    char cnt;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cnt='0';
            if(board[i][j] == '*'){
                mine[i][j] = '*';
                continue;
            }
            for(int k=0;k<8;k++){
                int nx = dx[k]+i;
                int ny = dy[k]+j;
                //cout << board[nx][ny] << endl;
                if(nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
                if(board[nx][ny] == '*') cnt++;
            }
            mine[i][j] = cnt;
        }
    }
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cout << mine[i][j];
        }
        cout << "\n";
    }

}

bool Input(){
    cin >> R >> C;
    Reset();
    if(R == 0 && C == 0) return true;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin >> board[i][j];
        }
    }
    Solution();
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    while(1){
        if(Input()) return 0;
    }
}