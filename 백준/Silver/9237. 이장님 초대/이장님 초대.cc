#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, tall, cnt=0;
vector<int> tree;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for(int i=0;i<N;i++){
        cin >> tall;
        tree.push_back(tall);
    }
    sort(tree.begin(), tree.end(), greater<int>());
    int max_time=0;

    for(int i=0;i<N;i++){
        int time = tree[i]+i+2;
        max_time = max(max_time, time);
    }
    cout << max_time;
}