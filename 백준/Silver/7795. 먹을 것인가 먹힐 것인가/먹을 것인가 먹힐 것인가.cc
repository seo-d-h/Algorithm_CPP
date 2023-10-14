#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--){
        int N, M, num, res = 0;
        vector<int> A, B;

        cin >> N >> M;
        for(int i=0;i<N;i++){
            cin >> num;
            A.push_back(num);
        }

        for(int i=0;i<M;i++){
            cin >> num;
            B.push_back(num);
        }

        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        for(auto& a : A){
            res += lower_bound(B.begin(), B.end(), a) - B.begin();
        }
        cout << res << "\n";
    }
}