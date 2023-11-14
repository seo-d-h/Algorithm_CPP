#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(int argc, char** argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int N, maxi=0;
  vector<int> vec;
  cin >> N;
  vec.resize(N);
  for(int i=0;i<N;i++){
    cin >> vec[i];
  }
  int a = vec[0];
  for(int i=1;i<N;i++){
    if(a > vec[i]){
      a = vec[i];
    }
    else if(a < vec[i]){
      maxi = max(maxi, vec[i]-a);
    }
  }
  cout << maxi;
   return 0;
}