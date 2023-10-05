#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k, t, m;

bool cmp(const vector<int>& a, const vector<int>& b){
    if(a[k+1] == b[k+1] && a[k+2] == b[k+2]){
        return a[k+3] > b[k+3];
    }
    else if(a[k+1] == b[k+1]){
        return a[k+2] < b[k+2];
    }
    return a[k+1] > b[k+1];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--){
        // n : 팀의 개수
        // k : 문제의 개수
        // t : 내 팀의 ID
        // m  : 로그 엔트리 개수
        
        cin >> n >> k >> t >> m;
        vector<vector<int>> table(n+1, vector<int>(k+4, 0));
        // k+1 : 점수 총합
        // k+2 : 제출 횟수
        while(m--){
            // i : 팀 ID
            // j : 문제 번호
            // s : 획득한 점수
            int i, j, s;
            cin >> i >> j >> s;
            table[i][0] = i;
            table[i][j] = max(table[i][j], s);
            //table[i][j] += s;
            table[i][k+2]++;
            table[i][k+3]=m;
        }

        for(int i=1;i<=n;i++){
            int summa = 0;
            for(int j=1;j<=k;j++){
                summa += table[i][j];
            }
            table[i][k+1] = summa;
        }

        sort(table.begin()+1, table.end(), cmp);

        // for(int i=1;i<=n;i++){
        //     for(int j=0;j<=k+3;j++){
        //         cout << table[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        for(int i=1;i<=n;i++){
            if(table[i][0] == t){
                cout << i << "\n";
            }
        }

    }
}