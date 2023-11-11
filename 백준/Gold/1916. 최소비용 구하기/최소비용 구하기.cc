#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <memory.h>
using namespace std;

int N, M;
vector<pair<int,int>> board[1002];
vector<int> dist(1002);

void Dijkstra(int start, int goal){
    priority_queue<pair<int,int>> pq;
    pq.push({0, start});
    dist[start] = 0;
    while(!pq.empty()){
        int cur_dist = -pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();
        if(dist[cur_node] < cur_dist){
            continue;
        }
        //cout << cur_node << " " << cur_dist << endl;
        for(int i=0;i<board[cur_node].size();i++){
            int next_dist = cur_dist + board[cur_node][i].first;
            int next_node = board[cur_node][i].second;
            if(next_dist < dist[next_node]){
                dist[next_node] = next_dist;
                pq.push({-next_dist, next_node});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    int start, goal;
    cin >> N >> M;
    fill(dist.begin(), dist.end(), INT_MAX);
    for(int i=0;i<M;i++){
        cin >> a >> b >> c;
        board[a].push_back({c,b});
    }
    cin >> start >> goal;

    Dijkstra(start, goal);
    cout << dist[goal];
}