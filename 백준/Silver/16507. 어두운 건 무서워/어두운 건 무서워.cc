#include<iostream>
using namespace std;
#define ll long long

int board[1002][1002];
ll sum[1002][1002];
int R, C, Q;
int r1, c1, r2, c2;

int main(int argc, char** argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  cin >> R >> C >> Q;
  for(int i=1;i<=R;i++){
    for(int j=1;j<=C;j++){
      cin >> board[i][j];
      sum[i][j] = sum[i][j-1]+board[i][j];
    }
  }

  while(Q--){
    int res = 0;
    cin >> r1 >> c1 >> r2 >> c2;
    for(int i=r1;i<=r2;i++){
      res += (sum[i][c2] - sum[i][c1-1]);
    }
    cout << res / ((r2-r1+1)*(c2-c1+1)) << "\n";
  }
   return 0;
}