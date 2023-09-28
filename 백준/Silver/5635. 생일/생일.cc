#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;

    cin >> n;
    vector<pair<pair<int,int>, pair<int,string>>> vec(n);
    for(int i=0;i<n;i++){
        cin >> vec[i].second.second >> vec[i].second.first >> vec[i].first.second >> vec[i].first.first;
    }

    sort(vec.begin(), vec.end());

    // for(auto a : vec){
    //     cout << a.first.first << a.first.second << a.second.first << a.second.second << endl;
    // }
    cout << vec[n-1].second.second << "\n" << vec[0].second.second;
}