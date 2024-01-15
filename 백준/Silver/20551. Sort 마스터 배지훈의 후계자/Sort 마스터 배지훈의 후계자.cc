#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, num;
vector<int> vec;

void Input(){
    cin >> N >> M;
    for(int i=0;i<N;i++){
        cin >> num;
        vec.push_back(num);
    }
    sort(vec.begin(), vec.end(), less<>());
}

void Output(){
    for(int i=0;i<N;i++){
        cout << vec[i] << " ";
    }
}

void Solution(){
    for(int i=0;i<M;i++){
        cin >> num;
        if(binary_search(vec.begin(), vec.end(), num)){
            cout << lower_bound(vec.begin(), vec.end(), num)-vec.begin() << "\n";
        }
        else cout << -1 << "\n";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    Input();
    Solution();

    return 0;
}