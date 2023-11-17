#include<iostream>


using namespace std;

int main(int argc, char** argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int N, res=0;
  int arr[1002];
  cin >> N;
  for(int i=0;i<N;i++){
    cin >> arr[i];
  }
  int start = arr[0];
  for(int i=1;i<=N;i++){
    if(arr[i-1] >= arr[i]){
      res = max(res, arr[i-1]-start);
      start = arr[i];
    }
  }
  //res = max(res, arr[N-1]-start);
  cout << res;
   return 0;
}