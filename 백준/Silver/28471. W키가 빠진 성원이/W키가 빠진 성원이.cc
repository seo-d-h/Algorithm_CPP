#include<iostream>
#include<queue>
#include<memory.h>
using namespace std;

int N;
char board[2002][2002];
int visited[2002][2002];
int cnt = 0;
int dx[7] = {-1,-1,0,0,1,-1,1};
int dy[7] = {-1,1,-1,1,-1,0,1};

bool BFS(int x, int y){
  bool flag = false;
  queue<pair<int,int>> Q;
  Q.push({x,y});
  visited[x][y] = 1;
  while(!Q.empty()){
    int cur_x = Q.front().first;
    int cur_y = Q.front().second;
    if(board[cur_x][cur_y] == '.'){
      cnt++;
    }
    Q.pop();
    for(int dir=0;dir<7;dir++){
      int nx = cur_x + dx[dir];
      int ny = cur_y + dy[dir];
      if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
      if(visited[nx][ny] || board[nx][ny] == '#') continue;
      Q.push({nx,ny});
      visited[nx][ny] = 1;
    }
  }
  if(flag) return true;
  else return false;
}

int main(int argc, char** argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  char ch;
  int x, y;
  cin >> N;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cin >> ch;
      board[i][j] = ch;
      if(ch == 'F'){
        x = i;
        y = j;
      }
    }
  }
  BFS(x,y);
  cout << cnt;
   return 0;
}