#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;

int T, N;
int cnt;
vector<int> vec[1002];
queue<int> Q;
int visited[1002];

void BFS(int x){
    Q.push(x);
    visited[x] = 1;
    while(!Q.empty()){
        int cur = Q.front();
        //cout << "cur : " << cur << endl;
        Q.pop();
        if(visited[vec[cur][0]]){
            cnt++;
            return;
        }
        Q.push(vec[cur][0]);
        visited[vec[cur][0]] = 1;
    }
}

int main ()
{
    int num;
    cin >> T;
    while(T--){
        cnt = 0;
        cin >> N;
        for(int i=1;i<=N;i++){
          cin >> num;
          vec[i].push_back(num);
        }
        for(int i=1;i<=N;i++){
            if(!visited[i]){
                BFS(i);    
            }
        }
        memset(visited, 0, sizeof(visited));
        memset(vec, 0, sizeof(vec));
        cout << cnt << "\n";
        while(!Q.empty()){
            Q.pop();
        }
    }

  return 0;
}
