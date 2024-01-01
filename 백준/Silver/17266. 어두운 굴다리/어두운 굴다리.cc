#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
int l, r, mid, res=0;
vector<int> vec;

bool solution(){        // 참이면 초과, 거짓이면 부족
    //cout << mid << endl;
    for(int i=0;i<M;i++){
        if(i==0){
            if(vec[0] - mid > 0) return false;
        }
        if(vec[i]-mid > vec[i-1]+mid) return false;
        if(i == M-1){
            if(vec[M-1] + mid < N) return false;
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    
    vec.resize(M);
    for(int i=0;i<M;i++){
        cin >> vec[i];
    }
    l = 1;
    r = N;

    while(l <= r){
        mid = (l+r)/2;
        if(!solution()){        // 높이 올리기
            l = mid+1;
        }
        else{       // 높이 낮추기
            r = mid-1;
            res = mid;
        }
    }
    cout << res;
}