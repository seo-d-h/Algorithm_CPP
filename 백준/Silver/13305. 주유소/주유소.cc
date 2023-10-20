#include <iostream>
#include <limits.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    ll res=0;
    ll mini = LONG_LONG_MAX;
    ll cost[100002];
    ll dist[100002];

    cin >> N;

    for(int i=0;i<N-1;i++){
        cin >> dist[i];
    }

    for(int i=0;i<N;i++){
        cin >> cost[i];
    }
    // mini = cost[0];
    // res += cost[0]*dist[0];
    for(int i=0;i<N-1;i++){
        mini = min(mini, cost[i]);
        res += mini * dist[i];
    }
    cout << res;
}