#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int arr[10];
int visited[10];
vector<int> vec;

void DFS(int cur, int cnt){
    if(cnt == M){
        for(int i=0;i<M;i++){
            cout << arr[i] << ' ';
        }
        cout << "\n";
        return;
    }
    for(int i=cur;i<N;i++){
        if(visited[i]) continue;
        visited[i] = 1;
        arr[cnt] = vec[i];
        DFS(i, cnt+1);
        visited[i] = 0;
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    vec.resize(N);
    for(int i=0;i<N;i++){
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    DFS(0, 0);
}