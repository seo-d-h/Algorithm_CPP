#include <iostream>
#include <vector>
using namespace std;

int N, S, cnt=0;
vector<int> vec;
int visited[100002];
bool flag=false;

void DFS(int x, int summa){
    //cout << summa << endl;
    if(summa == S){
        cnt++;
        //return;
    }
    //if(!flag) flag = true;
    for(int i=x;i<N;i++){
        //cout << i << ' ';
        if(visited[i]) continue;
        visited[i] = 1;
        DFS(i, summa+vec[i]);
        visited[i] = 0;
    }
}

int main(){
    ios :: sync_with_stdio(0);
    cin.tie(0);

    int num;
    cin >> N >> S;
    for(int i=0;i<N;i++){
        cin >> num;
        vec.push_back(num);
    }

    //visited[0] = 1;
    DFS(0,0);
    if(S == 0) cnt--;
    
    cout << cnt;
}