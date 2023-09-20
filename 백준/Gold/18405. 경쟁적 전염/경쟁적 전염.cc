#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int n, k, s,x,y;
int board[1002][1002];

typedef pair<int,int> vec;
typedef pair<int, vec> pv;

struct cmp{
    bool operator()(const pv& a, const pv& b){
        if(a.first != b.first){
            return a.first > b.first;
        }
        else{
            return board[a.second.first][a.second.second] > board[b.second.first][b.second.second];
        }
    }
};


priority_queue<pv, vector<pv>, cmp> PQ;

void BFS(){
    while(!PQ.empty()){
        int X = PQ.top().second.first;
        int Y = PQ.top().second.second;
        int Z = PQ.top().first;
        //cout << Z << " " << X << " " << Y << endl;
        PQ.pop();
        if(Z == s+1) return;
        for(int dir=0;dir<4;dir++){
            int nx = X + dx[dir];
            int ny = Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(board[nx][ny]) continue;
            board[nx][ny] = board[X][Y];
            PQ.push(make_pair(Z+1, make_pair(nx,ny)));
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> board[i][j];
            if(board[i][j] != 0){
                PQ.push(make_pair(1, make_pair(i,j)));
                
            }
        }
    }

    // while(!PQ.empty()){
    //     cout << "Q size" << PQ.size() << " " << get<0>(PQ.top()) << get<1>(PQ.top()) << get<2>(PQ.top())<< endl;
    //     PQ.pop();
    // }

    cin >> s >> x >> y;
    BFS();

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout << board[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << board[x-1][y-1];
}