// A B C D E F G H I J K L M
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int T, N;
char ch, cmp;
deque<char> dq;
bool flag;

void Solution(){
    cin >> T;
    while(T--){
        dq.clear();
        flag = 0;
        cin >> N;
        for(int i=0;i<N;i++){
            cin >> ch;
            if(!flag){
                cmp = ch;
                flag = 1;
                dq.push_back(cmp);
                continue;
            }
            if(cmp < ch){
                dq.push_back(ch);
            }
            else{
                cmp = ch;
                dq.push_front(ch);
            }
        }
        for(int i=0;i<N;i++){
            cout << dq[i];
        }
        cout << "\n";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Solution();
    return 0;
}