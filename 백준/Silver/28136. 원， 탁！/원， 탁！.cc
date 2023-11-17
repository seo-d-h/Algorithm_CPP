#include<iostream>
#include<deque>
#include<limits.h>
using namespace std;

int main(int argc, char** argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int N, num, cnt=1;
  int mini=INT_MAX;
  deque<int> dq;
  cin >> N;
  for(int i=0;i<N;i++){
    cin >> num;
    mini = min(mini,num);
    dq.push_back(num);
  }
  while(dq.front()!=mini){
    int tmp = dq.front();
    dq.pop_front();
    dq.push_back(tmp);
  }
  for(int i=1;i<dq.size();i++){
    if(dq[i] <= dq[i-1]) cnt++;
  }
  cout << cnt;
   return 0;
}