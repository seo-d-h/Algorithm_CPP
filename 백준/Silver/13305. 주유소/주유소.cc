#include <iostream>
#include <limits.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, res=0;
    int mini = INT_MAX;
    int cost[100002];
    int dist[100002];
    cin >> N;

    for(int i=0;i<N-1;i++){
        cin >> dist[i];
    }

    for(int i=0;i<N;i++){
        cin >> cost[i];
    }
    mini = cost[0];
    res += cost[0]*dist[0];
    for(int i=1;i<=N;i++){
        mini = min(mini, cost[i]);
        res += mini * dist[i];
    }
    cout << res;
}