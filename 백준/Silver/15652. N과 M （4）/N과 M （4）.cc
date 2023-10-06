#include <iostream>
using namespace std;

int n,m;
int arr[10];
int visited[10];

void DFS(int v, int cnt){
    if(cnt == m){
        for(int i=0;i<m;i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i=v;i<=n;i++){
        //if(visited[i]) continue;
        //visited[i] = 1;
        arr[cnt] = i;
        DFS(i, cnt+1); 
        //visited[i] = 0; 
    }
}

int main(){
    cin >> n >> m;
    DFS(1, 0);
}