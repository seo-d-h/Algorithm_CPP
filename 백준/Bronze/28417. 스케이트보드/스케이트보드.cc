#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, num;
    int maxi = 0;
    cin >> N;
    vector<int> vec;
    while(N--){
        int tmp = 0;
        vec.clear();
        for(int i=0;i<7;i++){
            cin >> num;
            vec.push_back(num);
        }
        if(vec[0] > vec[1]){
            tmp = vec[0];
        }
        else{
            tmp = vec[1];
        }
        sort(vec.begin()+2, vec.end(), greater<int>());
        tmp += vec[2] + vec[3];
        maxi = max(maxi, tmp);
    }
    cout << maxi;
}