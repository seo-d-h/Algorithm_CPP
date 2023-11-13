#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int N, num, res=1;
  vector<int> vec;
  cin >> N;
  for(int i=0;i<N;i++){
    cin >> num;
    vec.push_back(num);
  }
  for(int i=1;i<N;i++){
    if(vec[i-1] <= vec[i]) res++;
  }
  cout << res;
   return 0;
}