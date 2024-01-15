#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

int N, M;
int board[52][52];
vector<pair<pair<int,int>,bool>> chicken_house;
vector<pair<int,int>> house;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int res = INT_MAX, tmp;

void Input(){
    cin >> N >> M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin >> board[i][j];
            if(board[i][j] == 1) house.push_back({i,j});
            if(board[i][j] == 2) chicken_house.push_back({{i,j},0});
        }
    }
}

int Calculate(){
    int rtn_dist = 0;
    for(int i=0;i<house.size();i++){
        int dist = INT_MAX;
        for(int j=0;j<chicken_house.size();j++){
            if(chicken_house[j].second){
                dist = min(dist, abs(house[i].first-chicken_house[j].first.first) + abs(house[i].second-chicken_house[j].first.second));
            }
        }
        rtn_dist += dist;
    }
    //cout << rtn_dist << endl;
    return rtn_dist;
}

void Back(int idx, int cnt){
    if(cnt == M){
        res = min(res, Calculate());
        return;
    }
    for(int i=idx;i<chicken_house.size();i++){
        if(!chicken_house[i].second){
            chicken_house[i].second = 1;
            Back(i, cnt+1);
            chicken_house[i].second = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Input();
    Back(0, 0);
    cout << res;

    return 0;
}