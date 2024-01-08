#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <memory.h>
using namespace std;

int N, people, near, near_node, total = 0;
int res = INT_MAX;
vector<pair<int,int>> vec;
vector<pair<int,int>> vec_tree[12];
int bfs_visited[12];
int dfs_visited[12];

void Input(){
    cin >> N;
    vec.resize(N+1);
    for(int i=1;i<=N;i++){
        cin >> people;
        vec[i] = {i,people};
        total += people;
    }
    for(int i=1;i<=N;i++){
        cin >> near;
        for(int j=0;j<near;j++){
            cin >> near_node;
            vec_tree[i].push_back(vec[near_node]);
        }
    }
}

void Output(){
    for(int i=1;i<=N;i++){
        cout << i << " : ";
        for(auto a : vec_tree[i]){
            cout << a.first << " " << a.second << endl;
        }
        cout << endl;
    }
}

bool BFS(vector<int> V, bool TF){
    memset(bfs_visited, 0, sizeof(bfs_visited));
    int cnt = 0;
    queue<int> Q;
    Q.push(V[0]);
    bfs_visited[V[0]] = 1;
    while(!Q.empty()){
        int cur = Q.front();
        //cout << cur << " ";
        cnt++;
        Q.pop();
        for(int i=0;i<vec_tree[cur].size();i++){
            // 조건1 : 현재 노드와 연결되있다면
            // 조건2 : BFS로 방문한 적이 없다면
            // 조건3 : DFS의 방문여부와 동일하다면
            if(vec_tree[cur][i].first && !bfs_visited[vec_tree[cur][i].first] && dfs_visited[vec_tree[cur][i].first] == TF){
                bfs_visited[vec_tree[cur][i].first] = 1;
                Q.push(vec_tree[cur][i].first);
            }
        }
    }
    //cout << endl;
    if(V.size() != cnt) return false;
    return true;
}

bool check(){       
    vector<int> A, B;
    for(int i=1;i<=N;i++){
        if(dfs_visited[i]) A.push_back(i);
        else B.push_back(i);
    }
    if(!A.size() || !B.size()) return false;    // 빈벡터가 있으면 안됨
    if(BFS(A, true) == false) return false;       // 연결성 확인
    if(BFS(B, false) == false) return false;
    return true;
}

void calculate(){
    int A_num=0, B_num=0, diff=0;
    for(int i=1;i<=N;i++){
        if(dfs_visited[i]) A_num += vec[i].second;
        else B_num += vec[i].second;
    }
    diff = abs(A_num-B_num);
    if(diff < res) res = diff;
}

void DFS(int node, int cnt){
    if(cnt >= 1){
        if(check()){
            calculate();
            
        }
    }
    for(int i=node;i<=N;i++){
        if(dfs_visited[i]) continue;
        dfs_visited[i] = 1;
        DFS(i, cnt+1);
        dfs_visited[i] = 0;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Input();
    //Output();
    DFS(1,0);
    if(res == INT_MAX) cout << -1;
    else    cout << res;
}