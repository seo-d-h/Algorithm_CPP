#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  int N, Q;
  int L, R;
  vector<int> arr,sum;

  cin >> N >> Q;
  arr.resize(N+1);
  sum.resize(N+1);
  arr[0] = 0;
  for(int i=1;i<=N;i++){
    cin >> arr[i];
  }
  sort(arr.begin(), arr.end());
  sum[0] = 0;
  for(int i=1;i<=N;i++){
    sum[i] = sum[i-1]+arr[i];
  }
  
  for(int i=0;i<Q;i++){
    cin >> L >> R;
    cout << (sum[R]-sum[L-1]) << "\n";
  }
   return 0;
}