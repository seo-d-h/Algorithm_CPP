#include <iostream>
using namespace std;

int N, res=0;
int arr[10];
int tmp[10];
bool visited[10];

void DFS(int depth){
    if(depth == N){
        int add=0;
        for(int i=0;i<N-1;i++){
            int sub = abs(tmp[i]-tmp[i+1]);
            add += sub;
        }
        res = max(res, add);
    }
    for(int i=0;i<N;i++){
        if(visited[i]) continue;
        visited[i] = 1;
        tmp[depth] = arr[i];
        DFS(depth+1);
        visited[i] = 0;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    DFS(0);
    cout << res;
}