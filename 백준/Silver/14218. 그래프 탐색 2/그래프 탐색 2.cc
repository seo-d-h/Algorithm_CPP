#include<iostream>
#include<vector>
#include<queue>
#include<memory.h>
using namespace std;
int N, M;
vector<int> board[1002];
vector<int> vec;
int visited[1002];

void BFS(int start){
  queue<int> Q;
  Q.push(start);
  visited[start] = 0;
  while(!Q.empty()){
    int cur = Q.front();
    Q.pop();
    for(int i=0;i<board[cur].size();i++){
      if(visited[board[cur][i]] != -1) continue;
      Q.push(board[cur][i]);
      visited[board[cur][i]] = visited[cur]+1;
    }
  }
}


int main(int argc, char** argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int a, b;
  cin >> N >> M;
  for(int i=0;i<M;i++){
    cin >> a >> b;
    board[a].push_back(b);
    board[b].push_back(a);
  }

  int q;
  cin >> q;
  for(int i=1;i<=q;i++){
    cin >> a >> b;
    board[a].push_back(b);
    board[b].push_back(a);
    memset(visited,-1,sizeof(visited));
    BFS(1);
    for(int i=1;i<=N;i++){
      cout << visited[i] << " ";
    }
    cout << "\n";
    // board[a].pop_back();
    // board[b].pop_back();
  }
   return 0;
}