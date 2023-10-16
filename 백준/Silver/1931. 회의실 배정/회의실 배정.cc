#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const pair<int,int>& a, const pair<int,int>& b){
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, start, end, res = 1;
    vector<pair<int,int>> vec;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> start >> end;
        vec.push_back({end, start});
    }
    sort(vec.begin(), vec.end(), cmp);

    end = vec[0].first;
    for(int i=1;i<N;i++){
        //cout << vec[i].first << " " << vec[i].second << endl;
        if(vec[i].second >= end){
            end = vec[i].first;
            res++;
        }
    }
    cout << res;
}