#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int N, C, num, cnt=1;
map<int,int> mp;
map<int,int> priority;

bool cmp(const pair<int,int>& a, const pair<int,int>& b){
    if(a.second == b.second){
        return priority[a.first] < priority[b.first];
    }
    return a.second > b.second;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> C;
    for(int i=0;i<N;i++){
        cin >> num;
        mp[num]++;
        if(!priority[num]){
            priority[num] = cnt;
            cnt++;
        }
    }
    
    vector<pair<int,int>> vec(mp.begin(), mp.end());
    sort(vec.begin(), vec.end(), cmp);

    for(auto a : vec){
        //cout << a.first << " " << a.second << "\n";
        for(int i=0;i<a.second;i++){
            cout << a.first << " ";
        }
    }
}