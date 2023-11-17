#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n, m; 
    int a, result = 0;
    int l, r, mid, max_num=0;
    int l_idx, r_idx;
    vector<int> v;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    l = 0;
    r_idx = v.size()-1;
    r = v[r_idx];

    while(l<=r){
        long long int total=0;
        int mid = (l+r)/2;

        for(int i=0;i<n;i++){
            if(v[i] > mid){
                total += v[i] - mid;
            }
        }

        if(total >= m){     
            if(result < mid){
                result = mid;
            } 
            l = mid+1;
            
        }
        else{
            r = mid-1;
        }
    }

    
    cout << result;
}