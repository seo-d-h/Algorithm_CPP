#include<iostream>
#include<vector>
#include<map>
#include<memory.h>
using namespace std;

int main(int argc, char** argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int N, a, b;
  int res=0;
  int ary[12];
  memset(ary, -1, sizeof(ary));
  cin >> N;
  while(N--){
    cin >> a >> b;
    if(ary[a] == b){
      continue;
    }
    else{
      if(ary[a] == -1){
        ary[a] = b;
      }
      else{
        ary[a] = b;
        res++;
      }
    }
  }
  cout << res;
   return 0;
}