#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    int a, b, c;
    int num[102]={0,};
    vector<pair<int,pair<int,int>>> vec;

    cin >> N;
    for(int i=0;i<N;i++){

        cin >> a >> b >> c;
        vec.push_back({c,{a,b}});
    }

    sort(vec.begin(), vec.end(), greater<pair<int,pair<int,int>>>());
    
    int n = 0;
    for(int i=0;i<N;i++){
        if(num[vec[i].second.first] >= 2) continue;;
        cout << vec[i].second.first << ' ' << vec[i].second.second << endl;
        n++;
        num[vec[i].second.first]++;
        if(n == 3) break;
    }
}