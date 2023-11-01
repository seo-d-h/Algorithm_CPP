#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--){
        int N, M, cnt = 0;
        string str;
        cin >> N >> M;
        for(int i=N;i<=M;i++){
            str = to_string(i);
            for(int i=0;i<str.length();i++){
                if(str[i] == '0') cnt++;
            }
        }
        cout << cnt << "\n";
    }
}