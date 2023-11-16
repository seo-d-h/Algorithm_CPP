#include<iostream>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int N, goal, res=0;
  int arr[10002];
  cin >> N;
  for(int i=0;i<N;i++){
    cin >> arr[i];
  }
  cin >> goal;
  sort(arr, arr+N);
  int l, r, mid, sum;
  l = 0;
  r = arr[N-1];
  while(l <= r){
    sum = 0;
    mid = (l+r)/2;
    for(int i=0;i<N;i++){    // sum 구하기
      if(mid > arr[i]){
        sum += arr[i];
      }
      else sum += mid;
    }
    if(goal >= sum){
      res = mid;
      l = mid+1;
    }
    else{
      r=mid-1;
    }
  }
  cout << res;
   return 0;
}