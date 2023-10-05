#include <iostream>
#include <vector>

using namespace std;

int n, rm;
int tmp;
vector<int> vec[52];
int visited1[52];
int visited2[52];
int cnt = 0;

int DFS(int v){
    if(v == rm) return -1;
    if(vec[v].size() == 0){
        //cout << v << " ";
        cnt++;
        //return;
    }
    for(int i=0;i<vec[v].size();i++){
        if(DFS(vec[v][i]) == -1 && vec[v].size() == 1){
            cnt++;
        }
    }
    return 0;
}

int main(){
    int num, root;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> num;
        if(num != -1){
            vec[num].push_back(i);
        }
        else root = i;
    }
    cin >> rm;
    
    vec[rm].clear();
    //visited2[rm] = 1;
    
    //DFS(rm);
    //cout << endl;
    DFS(root);
    cout << cnt;
}