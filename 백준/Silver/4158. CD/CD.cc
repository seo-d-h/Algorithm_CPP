#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while(1){
        int N, M;
        int cnt = 0;
        vector<int> sangun, sunyung;
        
        cin >> N >> M;
        if(N == 0 && M == 0){
            return 0;
        }
        sangun.resize(N);
        sunyung.resize(M);
        for(int i=0;i<N;i++){
            cin >> sangun[i];
        }

        for(int i=0;i<M;i++){
            cin >> sunyung[i];
        }

        for(int a : sunyung){
            if(binary_search(sangun.begin(), sangun.end(), a)){
                cnt++;
            }
        }
        cout << cnt << "\n";
    }
}