#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int L, n, cnt = 0;
    vector<int> vec;
    cin >> L;
    vec.resize(L+1);
    //vec.push_back(0);
    for(int i=1;i<=L;i++){
        cin >> vec[i];
    }
    cin >> n;
    sort(vec.begin(), vec.end());
    // for(auto a : vec){
    //     cout << a << ' ';
    // }
    for(int i=1;i<=L;i++){
        //if(L > n) break;
        if(vec[i-1] < n && n < vec[i]){
            int start = vec[i-1]+1;
            int end = vec[i]-1;
            //cout << start << ' ' << end;
            for(int j=start;j<=end;j++){
                for(int k=j+1;k<=end;k++){
                    if(j <= n && n <= k) cnt++;
                    //cout << j << ',' << k << ' ';
                }
                //cout << endl;
            }
        }
    }
    cout << cnt;
}