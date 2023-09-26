#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

int N;
vector<int> vec;
queue<int> Q;
int dist[1002];
bool visited[1002];

void BFS(){
    Q.push(0);
    dist[0] = 0;
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        for(int i=1;i<=vec[cur];i++){
            int next = cur+i;
            if(next > N) return;
            if(dist[next] == -1){
                visited[next] = true;
                dist[next] = dist[cur]+1;
                Q.push(next);
            }
            
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int num;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> num;
        vec.push_back(num);
    }
    fill(dist, dist+1003, -1);
    BFS();

    // for(int i=0;i<N;i++){
    //     cout << dist[i] << " ";
    // }

    cout << dist[N-1];
    
}