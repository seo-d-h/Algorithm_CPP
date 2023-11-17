#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M;
vector<int> vec;
vector<int> res;
//int res[10]
int visited[10002];

void DFS(int x, int cnt){
  if(cnt == M){
    for(int a : res){
      cout << a << " ";
    }
    cout << "\n";
    return;
  }
  for(int i=0;i<N;i++){
    if(x == vec[i]){
      visited[x] = 0;
    }
    if(visited[vec[i]] || vec[i] < x) continue;
    visited[vec[i]] = 1;
    res.push_back(vec[i]);
    DFS(vec[i], cnt+1);
    res.pop_back();
    visited[vec[i]] = 0;
  }
}

int main(int argc, char** argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int num;
  cin >> N >> M;
  for(int i=0;i<N;i++){
    cin >> num;
    vec.push_back(num);
  }
  sort(vec.begin(), vec.end());
  DFS(0, 0);
   return 0;
}