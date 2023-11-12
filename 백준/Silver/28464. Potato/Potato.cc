#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    int park=0, sung=0;     // sung < park

    cin >> N;
    vector<int> vec;
    vec.resize(N);
    for(int i=0;i<N;i++){
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    int l = 0;
    int r = N-1;
    while(l <= r){
        sung += vec[l];
        park += vec[r];
        l++;
        r--;
    }
    if(N % 2 == 1){
        cout << sung-vec[l-1] << " " << park;
    }
    else{
        cout << sung << " " << park;
    }
    return 0;
}