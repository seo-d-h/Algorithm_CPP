#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int start_len=64;
    int X, cnt=0, res = 0;

    vector<int> vec;
    cin >> X;
    vec.push_back(start_len);
    while(start_len){
        vec.push_back(start_len/2);
        start_len /= 2;
    }
    vec.pop_back();

    for(auto a : vec){
        if(X >= res+a){
            res += a;
            cnt++;
            //cout << res << " ";
        }
    }
    cout << cnt;
}