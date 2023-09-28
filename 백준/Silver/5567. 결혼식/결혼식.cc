#include <iostream>
#include <vector>
using namespace std;

int n, m;
int res = 0;
vector<int> vec[502];
int visited[502];

void DFS(int cur, int cnt){
    visited[cur] = 1;
    if(cnt == 2){
        return;
    }
    else{
        for(int i=0;i<vec[cur].size();i++){
            DFS(vec[cur][i], cnt+1);
        }
    }
    return;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> n >> m;

    for(int i=0;i<m;i++){
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    DFS(1, 0);
    for(int i=2;i<=n;i++){
        if(visited[i]) res++;
    }
    cout << res;
}