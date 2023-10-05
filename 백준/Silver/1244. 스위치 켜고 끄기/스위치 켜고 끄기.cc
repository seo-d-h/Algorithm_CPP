#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, student_num;
    vector<int> vec;
    cin >> n;
    vec.resize(n+1);
    for(int i=1;i<=n;i++){
        cin >> vec[i];
    }

    cin >> student_num;
    while(student_num--){
        int a, b;
        cin >> a >> b;
        if(a == 1){
            for(int i=b;i<=n;i+=b){
                vec[i] ^= 1;
            }
        }
        else if(a == 2){
            vec[b] ^= 1;
            int mirror = 1;
            while(b-mirror >= 1 && b+mirror <= n && vec[b-mirror] == vec[b+mirror]){
                vec[b-mirror] ^= 1;
                vec[b+mirror] ^= 1;
                mirror++;
            }
        }
        // for(int i=1;i<=n;i++){
        //     cout << vec[i] << " ";
        // }
        // cout << "\n";
    }
    for(int i=1;i<=n;i++){
        cout << vec[i] << " ";
        if(i % 20 == 0){
            cout << "\n";
        }
    }
}