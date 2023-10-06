#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M;
    cin >> N;
    vector<int> vec(N), vec_sum(N+1);
    for(int i=1;i<=N;i++){
        cin >> vec[i];
    }

    vec_sum[0] = 0;
    for(int i=1;i<=N;i++){       // 구간합 구하기
        vec_sum[i] = vec[i] + vec_sum[i-1];
    }

    cin >> M;
    for(int k=0;k<M;k++){
        int i, j;
        cin >> i >> j;
        cout << vec_sum[j] - vec_sum[i-1] << "\n";
    }
}