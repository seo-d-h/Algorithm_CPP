#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, cnt=0;
    double res=0;
    int cut = 0;
    vector<int> vec;
    cin >> N;
    if(N==0){
        cout << res;
        return 0;
    }
    vec.resize(N);
    cut = round(N*0.15);
    for(int i=0;i<N;i++){
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    
    for(int i=cut;i<N-cut;i++){
        res += vec[i];
    }
    //cout << "res : " << res << endl;
    cout << round(res/(N-cut*2));
}