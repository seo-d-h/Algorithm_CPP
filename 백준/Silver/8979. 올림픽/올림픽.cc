#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const vector<int>& a, const vector<int>& b){
    if(a[1] == b[1] && a[2] == b[2]){
        return a[3] > b[3];
    }
    else if(a[1] == b[1]){
        return a[2] > b[2];
    }
    return a[1] > b[1];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, K;
    cin >> N >> K;
    vector<vector<int>> ary(N+1, vector<int>(4));
    int trial = N;
    //int ary[N+1][4];

    while(trial--){
        int num, gold, silver, bronz;
        cin >> num >> gold >> silver >> bronz;
        ary[num][0] = num;
        ary[num][1] = gold;
        ary[num][2] = silver;
        ary[num][3] = bronz;
    }

    sort(ary.begin(), ary.end(), cmp);
    vector<int> res;
    int cnt = 1;
    bool flag = 0;
    for(int i=0;i<N;i++){
        if(ary[i][1] == ary[i+1][1] && ary[i][2] == ary[i+1][2] && ary[i][3] == ary[i+1][3]){
            if(flag){
                res.push_back(res.back());
            }
            else{
                res.push_back(cnt);
                flag = 1;
            }
            
        }
        else{
            res.push_back(cnt);
            cnt++;
            flag = 0;
        }
    }

    // for(int i=0;i<N;i++){
    //     for(int j=0;j<4;j++){
    //         cout << ary[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // for(int a : res){
    //     cout << a << " ";
    // }

    cout << res[K-1];
}