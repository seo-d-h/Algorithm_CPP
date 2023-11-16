#include<iostream>
#include<vector>
#include<queue>
#include<memory.h>
using namespace std;

int N, M;
vector<int> board[20002];
int visited[20002];
int max_element;

void BFS(int start){
  queue<int> Q;
  Q.push(start);
  visited[start] = 0;
  while(!Q.empty()){
    int cur = Q.front();
    Q.pop();
    for(int i=0;i<board[cur].size();i++){
      if(visited[board[cur][i]] != -1) continue;
      visited[board[cur][i]] = visited[cur]+1;
      max_element = max(max_element, visited[board[cur][i]]);
      Q.push(board[cur][i]);
    }
  }
}

int main(int argc, char** argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  int a, b;
  int cnt=0, res=0;
  bool flag = false;
  cin >> N >> M;
  for(int i=0;i<M;i++){
    cin >> a >> b;
    board[a].push_back(b);
    board[b].push_back(a);
  }
  memset(visited, -1, sizeof(visited));
  BFS(1);
  for(int i=1;i<=N;i++){
    if(!flag && visited[i] == max_element){
      flag = 1;
      res = i;
    }
    if(visited[i] == max_element){
      cnt++;
    }
  }
  cout << res << " " << visited[res] << " " << cnt;
   return 0;
}