#include <iostream>
#include <queue>
using namespace std;

int board[5][5];

bool check(){
    int bingo = 0;
    if(board[0][0] == 0){       // 오른쪽 대각선 체크
        int cnt_r_cross=0;
        for(int i=0;i<5;i++){
            if(board[i][i] == 0){
                cnt_r_cross++;
            }
        }
        if(cnt_r_cross==5){
            bingo++;
        }
    }

    if(board[0][4] == 0){      // 왼쪽대각선 체크
        int cnt_l_cross=0;
        for(int i=4;i>=0;i--){
            if(board[4-i][i] == 0){
                cnt_l_cross++;
            }
        }
        if(cnt_l_cross==5){
            bingo++;
        }
    }

    for(int i=0;i<5;i++){       // 가로방향 체크
        int cnt_row=0;
        for(int j=0;j<5;j++){
            if(board[i][j] == 0){
                cnt_row++;
            }
        }
        if(cnt_row==5){
            bingo++;
        }
    }

    for(int i=0;i<5;i++){       // 세로방향 체크
        int cnt_l=0;
        for(int j=0;j<5;j++){
            if(board[j][i] == 0){
                cnt_l++;
            }
        }
        if(cnt_l==5){
            bingo++;
        }
    }

    if(bingo >= 3){
        return true;
    }
    return false;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int cnt=0, res = 0;;

    bool flag=false;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin >> board[i][j];
        }
    }

    for(int k=0;k<25;k++){
        cin >> n;
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                if(board[i][j] == n){
                    cnt++;
                    board[i][j] = 0;
                    if(check() && !flag){
                        flag = true;
                        res = cnt;
                    }
                }
            }
        }   
    }
    cout << res;
}