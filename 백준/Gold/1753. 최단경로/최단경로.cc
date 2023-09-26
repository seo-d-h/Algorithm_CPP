#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>
#include <limits.h>
using namespace std;

int V, E, K;
typedef pair<int,int> edge;
vector<vector<edge>> graph;
bool visited[20002];
int dist[20002];

void BFS(int start){
    priority_queue<edge, vector<edge>, greater<edge>> Q;
    Q.push({0,start});
    dist[start] = 0;
    while(!Q.empty()){
        edge cur = Q.top(); Q.pop();
        int cur_v = cur.second;
        //cout << cur_v << endl;
        if(visited[cur_v]) continue;
        visited[cur_v] = true;
        for(int i=0;i<graph[cur_v].size();i++){
            edge tmp = graph[cur_v][i];
            int next_v = tmp.first;
            int tmp_w = tmp.second;
            //cout << dist[next_v] << endl;
            if(dist[next_v] > dist[cur_v]+tmp_w){
                dist[next_v] = dist[cur_v]+tmp_w;
                Q.push({dist[next_v], next_v});
            }
        }
    }
}

int main(){
    int u,v,w;
    cin >> V >> E >> K;

    graph.resize(V+1);
    // memset(dist, INT_MAX, sizeof(dist));
    for(int i=1;i<=V;i++){
        dist[i] = INT_MAX;
    }

    for(int i=0;i<E;i++){
        cin >> u >> v >> w;
        graph[u].push_back({v,w});
    }
    
    BFS(K);

    for(int i=1;i<=V;i++){
        if(visited[i]){
            cout << dist[i] << "\n";
        }
        else{
            cout << "INF\n";
        }
    }
}