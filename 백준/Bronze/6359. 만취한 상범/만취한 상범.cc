#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<int> vec;
    vec.resize(102);
    int T, N;
    cin >> T;
    while(T--){
        int cnt = 0;
        cin >> N;
        for(int i=1;i<=N;i++){
            vec[i] = 1;
        }
        for(int i=2;i<=N;i++){
            for(int j=i;j<=N;j+=i){
                if(vec[j]==1){
                    vec[j] = 0;
                }
                else if(vec[j] == 0){
                    vec[j] = 1;
                }
            }
        }
        for(int i=1;i<=N;i++){
            if(vec[i]==1) cnt++;
        }
        cout << cnt << "\n";
        vec.clear();
    }
    
}