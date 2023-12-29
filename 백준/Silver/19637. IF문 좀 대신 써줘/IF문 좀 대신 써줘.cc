#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int n, m, score;
string name;
map<int, string> mp;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> name >> score;
        mp.insert({score, name});
    }
    for(int i=0;i<m;i++){
        cin >> score;
        auto iter = mp.lower_bound(score);
        cout << iter->second << "\n";
    }
}