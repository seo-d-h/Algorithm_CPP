#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int board[2250010];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int num=0;
    cin >> n;

    for(int i=0;i<n*n;i++){
        cin >> board[i];
    }

    sort(board, board+n*n, greater<int>());

    // for(int i=0;i<n*n;i++){
    //     cout << vec[i] << " ";
    // }
    cout << board[n-1];
}