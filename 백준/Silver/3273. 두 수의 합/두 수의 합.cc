#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, tmp, res, cnt=0;
    vector<int> v;

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> tmp;
        v.push_back(tmp);
    }
    cin >> res;

    int l = 0, r = n-1;
    sort(v.begin(), v.end());

    while(1){
        if(l >=r)
            break;
        int sum = v[l] + v[r];
        if(sum < res){
            l++;
        }
        else if(sum > res){
            r--;
        }
        else if(sum == res){
            cnt++;
            l++;
            r--;
        }
    }
    
    cout << cnt;
}