#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int M, N, res=0;
    vector<int> vec;
    cin >> M >> N;
    vec.resize(N);
    for(int i=0;i<N;i++){
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());

    int l, r, mid=0;
    l = 1;
    r = vec[N-1];
    while(l <= r){
        int cnt = 0;
        mid = (l+r)/2;
        for(int i=0;i<N;i++){
            if(mid!=0){
                cnt += vec[i]/mid;
            }
        }
        //cout << "l : " << l << ", r : " << r << ", mid : " << mid << ", cnt : "<< cnt<<  endl;
        if(cnt >= M){
            l = mid+1;
            res = mid;
        }
        else if(cnt < M) r = mid-1;
    }
    cout << res;
}