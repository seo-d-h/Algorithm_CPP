
#include <iostream>
#include <vector>
using namespace std;

int n, m, res=0, cnt = 0;
int board[2002][2002], check[2002];
vector<int> vec[2002];
bool flag = false;

void DFS(int cur, int cnt){
    //cout <<"cur : " <<  cur <<", cnt : " << cnt<<endl;
    if(cnt >= 4){
        flag = true;
        return;
    }
    for(int i=0;i<vec[cur].size();i++){
        if(check[vec[cur][i]] == 0){
            check[vec[cur][i]] = 1;
            DFS(vec[cur][i],cnt+1);
            check[vec[cur][i]] = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a,b;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> a >> b;
        // board[a][b] = 1;
        // board[b][a] = 1;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    
    for(int i=0;i<n;i++){
        fill(check, check+2001, 0);
        check[i] = 1;
        DFS(i,0);
        if(flag == 1) break;
    }
    
    //cout << "cnt : " << res << endl;
    if(flag) cout << 1;
    else cout << 0;
}