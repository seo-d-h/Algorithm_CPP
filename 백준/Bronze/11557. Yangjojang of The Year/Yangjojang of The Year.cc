#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

#define ll long long

using namespace std;

bool cmp(const pair<string,int> a, const pair<string,int>& b){
  return a.second > b.second;
}

int main(int argc, char** argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int T;
  cin >> T;
  while(T--){
    int N;
    cin >> N;
    vector<pair<string, int>> vec;
    string S;
    int L;
    for(int i=0;i<N;i++){
      cin >> S >> L;
      vec.push_back({S, L});
    }
    sort(vec.begin(), vec.end(), cmp);
    cout << vec[0].first << "\n";
  }
   return 0;
}