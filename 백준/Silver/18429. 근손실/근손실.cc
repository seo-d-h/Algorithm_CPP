#include <iostream>
#include <vector>
using namespace std;

int N, K, res=0;
vector<int> vec;
bool visited[10];

void DFS(int x, int weight, int cnt){
    if(weight < 500) return;
    //cout << weight << endl;
    if(cnt == N && weight >= 500){
        res++;
        //return;
    }
    for(int i=0;i<N;i++){
        if(visited[i]) continue;
        visited[i] = 1;
        DFS(i, weight+vec[i]-K, cnt+1);
        visited[i] = 0;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int num;
    cin >> N >> K;
    for(int i=0;i<N;i++){
        cin >> num;
        vec.push_back(num);
    }

    DFS(0, 500, 0);
    cout << res;
}