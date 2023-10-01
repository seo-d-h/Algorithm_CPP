#include <iostream>
#include <cmath>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,m;
    cin >> n >> m;
    int A[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> A[i][j];
        }
    }

    int p, q;
    cin >> p >> q;
    int B[p][q];
    for(int i=0;i<p;i++){
        for(int j=0;j<q;j++){
            cin >> B[i][j];
        }
    }

    int res[n][q];
    for(int i=0;i<n;i++){
        for(int j=0;j<q;j++){
            int tmp = 0;
            for(int k=0;k<m;k++){
                tmp += A[i][k]*B[k][j];
            }
            res[i][j] = tmp;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<q;j++){
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }

}