#include <iostream>
#include <queue>
using namespace std;

int board[102];
int visited[102];
int n,m,tmp;

void BFS(int x, int y){     
    queue<pair<int,int>> Q;
    visited[x] = 1;
    Q.push({x,y});
    while(!Q.empty()){
        int cur = Q.front().first;
        int cnt = Q.front().second;
        if(cur <= 0 || cur > 100) return;
        //cout << "cur : "<< cur << ", cnt : "<< cnt <<endl;
        Q.pop();
        for(int i=cur+1;i<=cur+6;i++){
            if(i <= 0 || i > 100) continue;
            if(visited[i]) continue;
            if(board[i]){
                visited[i] = cnt;
                //visited[board[i]] = cnt;
                Q.push({board[i], cnt+1});
                //cout << "i : "<< i << ", res : "<<visited[i] << endl;
            }
            else{
                visited[i] = cnt;
                Q.push({i, cnt+1});
                //cout << "i : "<< i << ", res : "<<visited[i] << endl;
            }
        }
        //if(cur+6 < 100) Q.push({cur+6, cnt+1});
    }
}

int main(){
    ios :: sync_with_stdio(0);
    cin.tie(0);

    int x, y;
    cin >> n >> m;
    for(int i=1;i<=n+m;i++){
        cin >> x >> y;
        board[x] = y;
    }

    BFS(1,1);       // 1 : 시작점, 0 : 카운트

    // for(int i=1;i<=100;i++){
    //     cout << "i : "<< i << ", res : "<<visited[i] << endl;
    // }
    cout << visited[100];
}