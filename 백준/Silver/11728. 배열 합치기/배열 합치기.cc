#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M;
    vector<int> A;
    cin >> N >> M;
    A.resize(N+M);
    for(int i=0;i<N+M;i++){
        cin >> A[i];
    }   
    sort(A.begin(), A.end());
    for(int i : A){
        cout << i << ' ';
    }
}