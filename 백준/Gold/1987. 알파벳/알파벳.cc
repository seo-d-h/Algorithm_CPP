#include <iostream>
using namespace std;

string map[22];
bool visit[25]= {0,};
int r, c, max_cnt = 0;;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void DFS(int x, int y, int cnt){
    visit[map[x][y]-'A'] = 1;
    max_cnt = max(max_cnt, cnt);
    //cout << "cur : " << map[x][y] << endl;
    for(int i=0;i<4;i++){
        int nx = dx[i] + x;
        int ny = dy[i] + y;
        if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
        if(visit[map[nx][ny] - 'A']) continue;
        //cout << nx << ny<< endl;
        visit[map[nx][ny] - 'A'] = 1;
        DFS(nx, ny, cnt+1);
        visit[map[nx][ny] - 'A'] = 0;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> r >> c;

    for(int i=0;i<r;i++){
        cin >> map[i];
    }

    // for(int i=0;i<r;i++){
    //     for(int j=0;j<c;j++){
    //         cout << map[i][j];
    //     }
    //     cout << endl;
    // }
    
    fill(visit, visit+25, 0);
    DFS(0,0,1);
    cout << max_cnt;
}