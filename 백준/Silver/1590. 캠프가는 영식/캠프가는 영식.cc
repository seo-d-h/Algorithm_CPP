#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,T,S,I,C;
int arr[1000002];
vector<int> vec;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> T;
    for(int i=0;i<n;i++){
        cin >> S >> I >> C;
        for(int j=0;j<C;j++){
            vec.push_back(S);
            S += I;
        }
    }
    sort(vec.begin(), vec.end());

    auto it = upper_bound(vec.begin(), vec.end(), T);
    
    if(binary_search(vec.begin(), vec.end(), T)){
        cout << 0;
    }
    else if(it != vec.end()){
        cout << *it-T;
    }
    else{
        cout << -1;
    }
}