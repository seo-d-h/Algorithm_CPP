#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int main(int argc, char** argv)
{  
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int N, K, num, maxi=INT_MIN;
  int arr[100002];
  cin >> N >> K;
  arr[0] = 0;
  for(int i=1;i<=N;i++){
    cin >> num;
    arr[i] = arr[i-1]+num;
  }
  for(int i=K;i<=N;i++){
    maxi = max(maxi, arr[i]-arr[i-K]);
  }
  cout << maxi;
  
  return 0;
}