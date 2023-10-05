#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;
 
int H, W;
const int MAX = 51;
char map[MAX][MAX];      //지도
bool visited[MAX][MAX];  //방문 표시
int path[MAX][MAX];      //경로 
int dy[] = { 0,0,-1,1 };
int dx[] = { -1,1,0,0 };
queue<pair<int, int>> q;
int max_len = 0;         //경로 중 최댓값
 
/*경로 배열의 최댓값을 리턴하는 BFS*/
int BFS(int y, int x) {
    path[y][x] = 1;
    visited[y][x] = true;
    q.push(make_pair(y, x));
 
    while (!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();
 
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
 
            if (ny < 0 || nx < 0 || ny >= H || nx >= W)
                continue;
            if (map[ny][nx] == 'L' && !visited[ny][nx]) {
                visited[ny][nx] = true;
                path[ny][nx] = path[y][x] + 1;
                q.push(make_pair(ny, nx));
                if (max_len < path[ny][nx]) {
                    max_len = path[ny][nx];
                }
            }
        }
    }
    return max_len - 1;
}
 
/*초기화*/
void reset() {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            visited[i][j] = 0;
            path[i][j] = 0;
        }
    }
    max_len = 0;
}
 
int main() {
    cin >> H >> W;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            scanf("%1s", &map[i][j]);
        }
    }
 
    /*모든 'L'에 대해 BFS 실행 -> 최댓값이 정답*/
    int ans = 0; 
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (map[i][j] == 'L') {
                int temp = BFS(i, j);
                if (temp > ans) {
                    ans = temp;
                }
                reset();
            }
        }
    }
 
    cout << ans;
}
