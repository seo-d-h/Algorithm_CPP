#include<iostream>
using namespace std;

int dx[8]={-1,-1,-1,0,1,1,1,0};
int dy[8]={-1,0,1,1,1,0,-1,-1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    char ch;
    char board[1002][1002];
    int int_board[1002][1002];
    char res[1002][1002];
    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> ch;
            if(ch != '.'){
                for(int dir=0;dir<8;dir++){
                    int nx = i+dx[dir];
                    int ny = j+dy[dir];
                    if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                    int_board[nx][ny] += ch-'0';
                }
                res[i][j] = '*';
            }
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(res[i][j] == '*') continue;
            else if(int_board[i][j] >= 10){
                res[i][j] = 'M';
            }
            else{
                res[i][j] = int_board[i][j]+'0';
            }
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout << res[i][j];
        }
        cout << "\n";
    }
}