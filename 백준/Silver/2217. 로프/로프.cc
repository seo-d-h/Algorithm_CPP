#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, num;
    int maxi = 0;
    vector<int> vec;

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> num;
        vec.push_back(num);
    }

    sort(vec.begin(), vec.end());
    for(int i=0;i<n;i++){
        maxi = max(maxi, vec[i]*(n-i));
    }
    cout << maxi;
}