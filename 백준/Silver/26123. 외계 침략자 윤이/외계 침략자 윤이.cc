#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
#define ll long long
int N, D, num;
priority_queue<int,vector<int>, less<int>> pq;
ll cntnum[300002];
ll res[300002];

int main(int argc, char** argv)
{
  cin >> N >> D;
  for(int i=0;i<N;i++){
    cin >> num;
    if(!cntnum[num]) pq.push(num);
    cntnum[num]++;
  }

  for(int i=0;i<D;i++){
    if(pq.empty()) continue;
    int top = pq.top();
    if(top == 0) break;
    res[i] = cntnum[top];
    pq.pop();
    
    if(pq.top() != top-1){
      pq.push(top-1);
    }
    cntnum[top-1] += cntnum[top]; 
  }
  for(int i=1;i<D;i++){
    res[i] = res[i-1] + res[i];
  }
  cout << res[D-1];
   return 0;
}