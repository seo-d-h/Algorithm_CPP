#include <iostream>
#include <queue>
using namespace std;

int V, E, start_node;
int s, e, d;
vector<pair<int, int>> board[20002];
int dist[300002];
priority_queue<pair<int,int>> PQ;

void Input(){
    cin >> V >> E >> start_node;
    for(int i=1;i<=E;i++){
        cin >> s >> e >> d;
        board[s].push_back({e,d});
    }
    for(int i=1;i<=V;i++){
        dist[i] = 300001;       // 최대값 대입
    }
}

void Output(){
    // board 출력
    // for(int i=0;i<E;i++){
    //     cout << i << " : " << endl;
    //     for(auto a : board[i]){
    //         cout << a.first << " " << a.second << endl;
    //     }
    // }
    for(int i=1;i<=V;i++){
        if(dist[i] == 300001)   cout << "INF\n";
        else    cout << dist[i] << "\n";
    }
}

void Djikstra(int d, int start){
    PQ.push({d, start});
    dist[start] = d;
    while(!PQ.empty()){
        int next_dist = -PQ.top().first;
        int cur_node = PQ.top().second;
        //cout << cur_node << " " << next_dist << endl;
        PQ.pop();
        if(dist[cur_node] < next_dist) continue;
        for(int i=0;i<board[cur_node].size();i++){
            if(dist[board[cur_node][i].first] > dist[cur_node]+board[cur_node][i].second){
                dist[board[cur_node][i].first] = dist[cur_node]+board[cur_node][i].second;
                PQ.push({-dist[board[cur_node][i].first], board[cur_node][i].first});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Input();
    Djikstra(0, start_node);
    Output();
}