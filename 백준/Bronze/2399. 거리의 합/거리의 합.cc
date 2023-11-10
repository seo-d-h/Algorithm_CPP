#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, num;
    long long res=0;
    vector<int> vec;
    cin >> N;

    for(int i=0;i<N;i++){
        cin >> num;
        vec.push_back(num);
    }

    for(int i=0;i<N;i++){
        for(int j=i;j<N;j++){
            res += abs(vec[i]-vec[j]);
        }
    }
    cout << res*2;
}