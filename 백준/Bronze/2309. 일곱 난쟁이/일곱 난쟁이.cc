#include<iostream>
#include<algorithm>
using namespace std;

int main(int argc, char** argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  int arr[9];
  int sum=0, minus, tmp1, tmp2;
  
  for(int i=0;i<9;i++){
    cin >> arr[i];
    sum += arr[i];
  }
  sort(arr, arr+9);
  minus = sum - 100;
  for(int i=0;i<9;i++){
    for(int j=i+1;j<9;j++){
      if(arr[i]+arr[j] == minus){
        tmp1 = arr[i];
        tmp2 = arr[j];
      }
    }
  }
  for(int i=0;i<9;i++){
    if(arr[i] == tmp1 || arr[i] == tmp2) continue;
    cout << arr[i] << "\n";
  }
   return 0;
}