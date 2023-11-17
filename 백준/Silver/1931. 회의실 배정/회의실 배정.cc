#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(const pair<int,int>& a , const pair<int,int>& b){
  if(a.second == b.second){
    return a.first < b.first;
  }
  return a.second < b.second;
}

int main(int argc, char** argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  int N, a, b;
  int res=1;
  vector<pair<int,int>> room;
  cin >> N;
  for(int i=0;i<N;i++){
    cin >> a >> b;
    room.push_back({a,b});
  }
  sort(room.begin(), room.end(), cmp);
  int start = room[0].first;
  int end = room[0].second;
  for(int i=1;i<N;i++){
    if(end <= room[i].first){
      start = room[i].first;
      end = room[i].second;
      res++;
    }
  }
  cout << res;
   return 0;
}