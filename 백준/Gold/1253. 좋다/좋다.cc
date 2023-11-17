#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long
int main(int argc, char** argv)
{
  int N, res=0; 
  ll num;
  vector<ll> vec;
  cin >> N;
  for(int i=0;i<N;i++){
    cin >> num;
    vec.push_back(num);
  }
  sort(vec.begin(), vec.end());

  for(int i=0;i<N;i++){
    ll cur = vec[i];
    int l = 0, r = N-1;
    while(l < r){
      if(vec[l]+vec[r] == cur){
        if(l != i && r != i){
          res++;
          break;
        }
        if(l == i) l++;
        if(r == i) r--;
      }
      else if(vec[l]+vec[r] > cur){
        r--;
      }
      else if(vec[l]+vec[r] < cur){
        l++;
      }
    }
  }
  cout << res;
  
   return 0;
}