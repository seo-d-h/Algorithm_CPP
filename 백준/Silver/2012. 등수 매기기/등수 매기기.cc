#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, num;
    long long res = 0;
    vector<int> vec;
    cin >> N;
    vec.resize(N+1);
    for(int i=1;i<=N;i++){
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end());

    for(int i=1;i<=N;i++){
        res += abs(i-vec[i]);
    }
    cout << res;
}