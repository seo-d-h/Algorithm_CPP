#include <iostream>
#include <vector>
using namespace std;

int N;
int visited[10];
vector<int> vec;

void DFS(int cnt){
    if(cnt == N){
        for(int i=0;i<N;i++){
            cout << vec[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i=1;i<=N;i++){
        if(visited[i]) continue;
        visited[i] = 1;
        vec.push_back(i);
        DFS(cnt+1);
        vec.pop_back();
        visited[i] = 0;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    DFS(0);
}