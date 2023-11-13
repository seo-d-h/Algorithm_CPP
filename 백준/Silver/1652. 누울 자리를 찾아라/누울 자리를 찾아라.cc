#include <iostream>
using namespace std;

char ch;
int N;
int res_row=0, res_col=0;
char board[102][102];

void cnt_row(){
  for(int i=0;i<N;i++){
    int cnt=0;
    for(int j=0;j<N;j++){
      if(board[i][j] == '.'){
        cnt++;
      }
      else{
        if(cnt >= 2) res_row++;
        cnt = 0;
      }
    }
    if(cnt >= 2) res_row++;
  }
}

void cnt_col(){
  for(int i=0;i<N;i++){
    int cnt=0;
    for(int j=0;j<N;j++){
      if(board[j][i] == '.'){
        cnt++;
      }
      else{
        if(cnt >= 2) res_col++;
        cnt = 0;
      }
    }
    if(cnt >= 2) res_col++;
  }
}

int main(int argc, char** argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cin >> ch;
      board[i][j] = ch;
    }
  }

  cnt_row();
  cnt_col();
  
  cout << res_row << " " << res_col;
  
   return 0;
}