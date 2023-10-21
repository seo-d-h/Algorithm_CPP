#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

int N;
int max_dist=0;
int max_node=0;
vector<pair<int,int>> V[100002];
int visited[100002];

void DFS(int cur, int dist){
    //cout << "cur : " << cur << ", dist : " << dist << endl;
    if(visited[cur]) return;
    visited[cur] = 1;
    if(max_dist < dist){
        max_dist = dist;
        max_node = cur;
    }
    //cout << cur << endl;
    for(int i=0;i<V[cur].size();i++){
        //visited[V[cur][i].first] = 1;
        DFS(V[cur][i].first, dist+V[cur][i].second);
        //visited[V[cur][i].first] = 0;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0;i<N;i++){
        int node;
        cin >> node;
        while(1){
            int a, b;
            cin >> a;
            if(a == -1) break;
            cin >> b;
            V[node].push_back({a,b});
        }
    }

    // for(int i=0;i<N;i++){
    //     cout << i << " : ";
    //     for(auto a : V[i]){
    //         cout << a.first << ' ' << a.second << endl;
    //     }
    // }
    //visited[1] = 1;
    //memset(visited, 0, sizeof(visited));
    DFS(1,0);
    memset(visited, 0, sizeof(visited));
    max_dist=0;
    DFS(max_node, 0);
    cout << max_dist;
}