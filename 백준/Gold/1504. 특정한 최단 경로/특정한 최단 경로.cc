#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>
using namespace std;

#define MAX 987654321

int N, E;
int a, b, c;
int u, v;
long long  res=MAX;
vector<pair<int,int>> vec[802];
long long dist[200002];
bool flag=0;
long long NtoU, NtoV, UtoV, UtoN, VtoN, VtoU;

void Input(){
    cin >> N >> E;
    for(int i=1;i<=E;i++){
        cin >> a >> b >> c;
        vec[a].push_back({b,c});
        vec[b].push_back({a,c});
        dist[i] = MAX;
    }
    for(int i=1;i<=N;i++){
        dist[i] = MAX;
    }
    cin >> u >> v;
    if(u < v) return;
    else{
        swap(u,v);
    }
}

void Reset(){
    for(int i=1;i<=N;i++){
        dist[i] = MAX;
    }
}

void Djikstra(int start){
    Reset();
    priority_queue<pair<int,int>> Q;
    Q.push({0, start});     // 거리, 노드 순으로 저장
    dist[start] = 0;
    while(!Q.empty()){
        int cur_node = Q.top().second;
        int cur_dist = -Q.top().first;
        //cout << "cur_node : " << cur_node << ", cur_dist : " << cur_dist << endl;
        Q.pop();
        for(int i=0;i<vec[cur_node].size();i++){
            int next_node = vec[cur_node][i].first;
            int next_dist = vec[cur_node][i].second;
            //cout << "next_node : " << next_node << ", next_dist : " << next_dist << endl;
            if(dist[next_node] > cur_dist+next_dist){
                dist[next_node] = cur_dist+next_dist;
                Q.push({-dist[next_node], next_node});
            }
        }
    }
}

void Output(){
    for(int i=1;i<=N;i++){
        cout << dist[i] << " ";
    }
    cout << endl;
}

void Solution(){
    Djikstra(1);    
    NtoU = dist[u];
    NtoV = dist[v];

    Djikstra(u);
    UtoV = dist[v];
    UtoN = dist[N];

    Djikstra(v);
    VtoN = dist[N];
    VtoU = dist[u];
    

    res = min(res, NtoU+UtoV+VtoN); // 1 -> u -> v -> N
    res = min(res, NtoV+VtoU+UtoN); // 1 -> v -> u -> N
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Input();
    Solution();
    
    if(res == MAX || UtoV == MAX || VtoU == MAX)  cout << -1;
    else    cout << res; 

    return 0;
}