#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

int T, res=0, deep=0;
vector<int> vec[1002];
int visited[1002];

void DFS(int cur, int dist){
    if(visited[cur]) return;
    if(res < dist){
        res = dist;
        deep = cur;
    }
    //cout << "cur : " << cur << ", dist : " << dist << endl;
    visited[cur] = 1;
    for(int i=0;i<vec[cur].size();i++){
        DFS(vec[cur][i], dist+1);
        //visited[vec[cur][i]] = 0;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    while(T--){
        //memset(visited, 0, sizeof(visited));
        res = 0;
        int N, M;
        int a, b;
        cin >> N >> M;
        for(int i=0;i<M;i++){
            cin >> a >> b;
            vec[a].push_back(b);
            vec[b].push_back(a);
        }
        //DFS(1, 0);
        cout << N-1 << "\n";
    }
}