#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, num;
    vector<int> vec;
    cin >> N;
    //vec.resize(N);
    for(int i=1;i<=N;i++){
        cin >> num;
        vec.insert(vec.begin()+num, i);
    }
    reverse(vec.begin(), vec.end());
    for(auto a : vec){
        cout << a << " ";
    }
}