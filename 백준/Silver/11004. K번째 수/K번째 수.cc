#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k, num;
    vector<int> vec;
    cin >> n >> k;

    for(int i=0;i<n;i++){
        cin >> num;
        vec.push_back(num);
    }
    sort(vec.begin(), vec.end());
    cout << vec[k-1];
}