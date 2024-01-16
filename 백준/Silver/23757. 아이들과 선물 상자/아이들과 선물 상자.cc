#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, num;
vector<int> children;
priority_queue<int> present;
bool flag = 0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for(int i=0;i<N;i++){
        cin >> num;
        present.push(num);
    }
    for(int i=0;i<M;i++){
        cin >> num;
        if(present.top() < num){        // 값이 가장 큰 선물상자보다 가져가려는게 더 크면
            cout << 0;
            return 0;
        }
        else{
            int tmp = present.top();
            present.pop();
            tmp -= num;
            present.push(tmp);
        }
    }

    cout << 1;
    return 0;
}