#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(int argc, char** argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  int K, N;
  cin >> K;
  for(int i=1;i<=K;i++){
    int mini, maxi, gap=0;
    cin >> N;
    vector<int> vec;
    vec.resize(N);
    for(int j=0;j<N;j++){
      cin >> vec[j];
    }
    sort(vec.begin(), vec.end());
    mini = vec[0];
    maxi = vec.back();
    for(int j=1;j<N;j++){
      gap = max(gap, vec[j] - vec[j-1]);
    }
    
    cout << "Class " << i <<"\n";
    cout << "Max " << maxi << ", Min " << mini << ", Largest gap " << gap << "\n";
  }
   return 0;
}