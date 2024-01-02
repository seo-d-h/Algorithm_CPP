#include <iostream>
using namespace std;

int N, res=0;
int board[225];
bool visited1[225];
bool visited2[225];
bool visited3[225];

int Back(int cur){
    if(cur == N){
        res++;
    }
    for(int i=0;i<N;i++){
        if(visited1[i] || visited2[cur+i] || visited3[cur-i+N-1]) continue;
        visited1[i] = 1;
        visited2[cur+i] = 1;
        visited3[cur-i+N-1] = 1;
        Back(cur+1);
        visited1[i] = 0;
        visited2[cur+i] = 0;
        visited3[cur-i+N-1] = 0;
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    Back(0);
    cout << res;
}