#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, a, res=0;
vector<int> house;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for(int i=0;i<N;i++){
        cin >> a;
        house.push_back(a);
    }
    while(1){
        sort(house.begin(), house.end(), greater<int>());
        if(house[0] == 0){
            break;
        }
        house[0]--;
        if(house[1]){
            house[1]--;
        }
        res++;
    }
    if(res >= 1441){
        cout << -1;
    }
    else{
        cout << res;
    }
}