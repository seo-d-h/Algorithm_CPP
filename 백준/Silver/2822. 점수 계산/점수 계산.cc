#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int res = 0;
  vector<int> vec;
  vector<int> vec_res;
  vec.resize(8);
  for(int i=0;i<8;i++){
    cin >> vec[i];
  }

  for(int i=0;i<5;i++){
    int mini = 0;
    int tmp = 0;
    for(int j=0;j<8;j++){
      if(mini < vec[j]){
        mini = vec[j];
        tmp = j;
      }
    }
    vec[tmp] = -1;
    res += mini;
    vec_res.push_back(tmp+1);
  }
  sort(vec_res.begin(), vec_res.end());
  cout << res << "\n";
  for(int a : vec_res){
    cout << a << " ";
  }
   return 0;
}