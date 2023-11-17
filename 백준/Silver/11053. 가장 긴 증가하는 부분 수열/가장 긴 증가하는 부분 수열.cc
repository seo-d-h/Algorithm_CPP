#include<iostream>


using namespace std;

int main(int argc, char** argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int N, res=0;
  int arr[1002];
  int dp[1002];
  fill(dp, dp+1002, 1);
  
  cin >> N;
  for(int i=0;i<N;i++){
    cin >> arr[i];
  }
  
  for(int i=0;i<N;i++){
    for(int j=0;j<i;j++){
      if(arr[i] > arr[j]){
        dp[i] = max(dp[j]+1, dp[i]);
      }
    }
  }
  for(int i=0;i<N;i++){
    res = max(res, dp[i]);
  }
  cout << res;
  return 0;
}