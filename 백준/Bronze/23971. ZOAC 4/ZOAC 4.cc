#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int H, W, N, M;
    int cnt = 0;
    cin >> H >> W >> N >> M;

    for(int i=0;i<H;i+=(N+1)){
        for(int j=0;j<W;j+=(M+1)){
            //cout << i << " " << j << endl;
            cnt++;
        }
    }
    cout << cnt;
}