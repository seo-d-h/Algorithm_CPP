#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

#define RED 1
#define BLUE 2

vector<int> vec[20002];
int visited[20002];
int V, E;

void DFS(int cur){
    if(!visited[cur]){
        visited[cur] = RED;
    }
    for(int i=0;i<vec[cur].size();i++){
        int idx = vec[cur][i];
        if(!visited[idx]){
            if(visited[cur] == RED){
                visited[idx] = BLUE;
            }
            else if(visited[cur] == BLUE){
                visited[idx] = RED;
            }
            DFS(idx);
        }
    }
}

bool check(){
    for(int i=1;i<=V;i++){
        if(vec[i].empty()) continue;
        for(int j=0;j<vec[i].size();j++){
            int idx = vec[i][j];
            if(visited[i] == visited[idx]){
                return false;
            }
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int K;
    int a, b;
    cin >> K;
    while(K--){
        cin >> V >> E;
        for(int i=0;i<E;i++){
            cin >> a >> b;
            vec[a].push_back(b);
            vec[b].push_back(a);
        }

        for(int i=1;i<=V;i++){
            if(visited[i] == 0){
                DFS(i);
            }
        }
        
        if(check()){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
        memset(vec, 0, sizeof(vec));
        memset(visited, 0, sizeof(visited));
    }
}