#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const vector<int>& a, const vector<int>& b){
    if(a[1] == b[1] && a[2] == b[2] && a[3] == b[3]){
        return a[0] < b[0];
    }
    else if(a[1] == b[1] && a[2] == b[2]){
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
    vector<vector<int>> ary(N+1, vector<int>(5));
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
    res.resize(N);
    int rank = 1;
    ary[0][4] = 1;

    for(int i=1;i<N;i++){
        if(ary[i][1] == ary[i-1][1] && ary[i][2] == ary[i-1][2] && ary[i][3] == ary[i-1][3]){
            ary[i][4] = ary[i-1][4];
        }
        else{
            rank = i+1;
            ary[i][4] = rank;
        }
    }

    // for(int i=0;i<N;i++){
    //     for(int j=0;j<5;j++){
    //         cout << ary[i][j] << " ";
    //     }
    //     cout << endl;
    // }


    for(int i=0;i<N;i++){
        if(ary[i][0] == K) cout << ary[i][4];
    }
}