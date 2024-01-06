#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>
#include <memory.h>
#include <algorithm>
using namespace std;

int N, M;       // N : Node, M : Edge
int a, b;
int visited[102];
int mini = INT_MAX;
vector<int> vec[102];
vector<pair<int,int>> cabin;
queue<int> Q;

bool cmp(const pair<int,int> & a, const pair<int,int> & b){
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int BFS(int start){
    int add=0;
    Q.push(start);
    visited[start] = 0;
    while(!Q.empty()){
        int cur = Q.front();
        Q.pop();
        add += visited[cur];
        for(int i=0;i<vec[cur].size();i++){
            if(visited[vec[cur][i]] != -1) continue;
            visited[vec[cur][i]] = visited[cur]+1;
            Q.push(vec[cur][i]);
        }
    }
    return add;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int res=0;
    cin >> N >> M;
    for(int i=0;i<M;i++){
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    for(int i=1;i<=N;i++){
        memset(visited, -1, sizeof(visited));
        res = BFS(i);
        cabin.push_back({i, res});
        //cout << "res : " << res << endl;
    }   
    sort(cabin.begin(), cabin.end(), cmp);
    
    cout << cabin[0].first;
}