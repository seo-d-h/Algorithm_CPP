#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, cnt=0;
    vector<int> vec;
    cin >> N;
    vec.resize(N);
    
    for(int i=0;i<N;i++){
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end());
    for(int i=0;i<N;i++){
        long long cur = vec[i];
        int l=0, r=N-1;
        //cout << summa << endl;
        while(l < r){
            //cout << "cur : " << cur << ", l : " << l << " , r : " << r<<", summa : " << vec[l]+vec[r] << endl;
            if(vec[l]+vec[r] == cur){
                if(l != i && r != i){
                    cnt++;
                    break;
                }
                else if(l == i) l++;
                else if(r == i) r--;
            }
            else if(vec[l]+vec[r] > cur){
                r--;
            }
            else if(vec[l]+vec[r] < cur){
                l++;
            }
        }
    }
    cout << cnt;
}