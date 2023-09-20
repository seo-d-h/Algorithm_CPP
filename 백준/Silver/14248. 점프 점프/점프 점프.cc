#include <iostream>
#include <queue>
using namespace std;

int n;
int board[100002];
int visited[100002];
int cnt = 0;
queue<int> Q;

void BFS(int x){
    Q.push(x);
    visited[x] = 1;
    cnt++;
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        //cout << "\ncur : " << cur;
        for(auto a : {cur+board[cur], cur-board[cur]}){   // a : 인덱스
            //cout << ", a : " << a;
            if(a < 1 || a > n) continue;
            if(visited[a]) continue;
            visited[a] = 1;
            cnt++;
            Q.push(a);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num, s;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> num;
        board[i] = num;
    }
    cin >> s;
    BFS(s);

    // for(int i=1;i<=n;i++){
    //     cout << visited[i] << " ";
    // }

    cout << cnt;
}