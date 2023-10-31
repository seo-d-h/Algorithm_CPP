#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, L, num;
    vector<int> vec;
    cin >> N >> L;
    for(int i=0;i<N;i++){
        cin >> num;
        vec.push_back(num);
    }
    sort(vec.begin(), vec.end());
    for(int i=0;i<N;i++){
        if(L >= vec[i]){
            L++;
        }
        else break;
    }
    cout << L;
}