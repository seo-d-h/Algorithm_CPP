#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

int t;
vector<int> res;
vector<int> vec;
int visited[50];

void Back(int n, int cnt){
    if(cnt == 6){
        for(int a : res){
            cout << a << " ";
        }
        cout << "\n";
        return;
    }
    for(int i = n;i<t;i++){
        if(visited[vec[i]]) continue;
        res.push_back(vec[i]);
        visited[vec[i]] = 1;
        Back(i, cnt+1);
        res.pop_back();
        visited[vec[i]] = 0;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(1){
        cin >> t;
        if(t == 0) break;
        vec.resize(t);
        for(int i=0;i<t;i++){
            cin >> vec[i];
        }
        Back(0, 0);
        memset(visited, 0, sizeof(visited));
        vec.clear();
        res.clear();
        cout << "\n";
    }
    return 0;
}