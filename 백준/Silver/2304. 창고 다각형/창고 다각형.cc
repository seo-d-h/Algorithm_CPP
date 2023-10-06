#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> vec(1001);
    stack<pair<int,int>> lstk, rstk;

    int N;
    int maxi_h = 0;
    int maxi_idx = 0;
    int res = 0;
    cin >> N;
    for(int i=0;i<N;i++){
        int L, H;
        cin >> L >> H;
        vec[L] = H;
        if(maxi_h < H){
            maxi_h = H;
            maxi_idx = L;
        }
    }

    int left = 0;
    for(int i=1;i<maxi_idx;i++){
        left = max(left, vec[i]);
        //cout << left << endl;
        res+=left;
    }

    int right = 0;
    for(int i=1000;i>maxi_idx;i--){
        right = max(right, vec[i]);
        //cout << right << endl;
        res += right;
    }


    cout << res + maxi_h;
}