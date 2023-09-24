#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool cmp(const pair<string, int>& a, const pair<string, int>& b){
    if(a.second != b.second) return a.second > b.second;
    if(a.first.length() != b.first.length()) return a.first.length() > b.first.length();
    return a.first < b.first;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    string str;
    map<string, int> mp;

    cin >> n >> m;

    for(int i=0;i<n;i++){
        cin >> str;
        if(str.length() < m) continue;

        if(mp.find(str) != mp.end()){       // key값이 이미 있으면
            mp[str]++;
        }
        else{
            mp.insert({str, 1});
        }
    }

    vector<pair<string,int>> vec(mp.begin(), mp.end());
    sort(vec.begin(), vec.end(), cmp);

    for(auto a : vec){
        cout << a.first << "\n";
    }

}