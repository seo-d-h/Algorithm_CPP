#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAX 987654321

int T;
int n, d, c;        
// n : 컴퓨터 개수, d : 의존성(간선) 개수, c : 해킹당한 컴퓨터 번호(시작노드)
int a, b, s;
vector<pair<int,int>> vec[10002];
int dist[10002];

void Reset(){
    for(int i=1;i<=n;i++){
        vec[i].clear();
        dist[i] = MAX;
    }
}

void Djik(int start){
    priority_queue<pair<int,int>> Q;
    Q.push({0, start});
    dist[start] = 0;
    while(!Q.empty()){
        int cur_node = Q.top().second;
        int cur_dist = -Q.top().first;
        Q.pop();
        for(int i=0;i<vec[cur_node].size();i++){
            int next_node = vec[cur_node][i].second;
            int next_dist = vec[cur_node][i].first;
            if(dist[next_node] > cur_dist+next_dist){
                dist[next_node] = cur_dist+next_dist;
                Q.push({-dist[next_node], next_node});
            }
        }
    }
}

void Output(){
    int cnt=0;
    int maxi = 0;
    for(int i=1;i<=n;i++){
        if(dist[i] != MAX){
            cnt++;
            maxi = max(maxi, dist[i]);
        }
    }
    cout << cnt << " " << maxi << "\n";
}

void Input(){
    cin >> T;
    while(T--){
        cin >> n >> d >> c;
        Reset();
        for(int i=0;i<d;i++){
            cin >> a >> b >> s;
            vec[b].push_back({s,a});
        }
        Djik(c);
        Output();
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Input();

    return 0;
}