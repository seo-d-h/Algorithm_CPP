#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, num;
    int mean = 0, mid = 0, freq = 0, range = 0;
    vector<int> vec;
    cin >> n;
    while(n--){
        cin >> num;
        vec.push_back(num);
    }
    sort(vec.begin(), vec.end());

    //! 1. 산술평균 구하기
    double tmp = 0;
    for(int a : vec){
        tmp += a;
    }
    mean = round(tmp / vec.size());

    //! 2. 중앙값 구하기
    mid = vec[vec.size()/2];

    //! 3. 최빈값 구하기
    int cnt_redund = 0;
    map<int,int> mp;
    for(int a : vec){
        if(mp.find(a) != mp.end()){
            mp[a]++;
        }
        else{
            mp.insert({a, 1});
        }
    }

    int maxFreq = 0;
    vector<int> mode;
    for(auto pair : mp){
        if(pair.second > maxFreq){
            maxFreq = pair.second;
            mode.clear();
            mode.push_back(pair.first);
        }
        else if(pair.second == maxFreq){
            mode.push_back(pair.first);
        }
    }

    sort(mode.begin(), mode.end());
    // for(auto a : mode){
    //     cout << "mode : " << a << endl;
    // }

    if(mode.size() >= 2){
        freq = mode[1];
    }
    else{
        freq = mode[0];
    }
    
    //! 4. 범위 구하기
    range = vec.back() - vec.front();


    cout << mean << "\n" << mid << "\n" << freq << "\n" << range;
}