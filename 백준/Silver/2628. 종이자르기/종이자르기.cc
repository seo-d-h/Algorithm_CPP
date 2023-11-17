#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(int argc, char** argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  int N, M, split;
  int a, b;
  int res=0;
  vector<int> row;
  vector<int> col;
  row.push_back(0);
  col.push_back(0);
  cin >> N >> M >> split;
  for(int i=0;i<split;i++){
    cin >> a >> b;
    if(a == 1){
      col.push_back(b);
    }
    else if(a == 0){
      row.push_back(b);
    }
  }
  row.push_back(M);
  col.push_back(N);
  sort(row.begin(), row.end());
  sort(col.begin(), col.end());
  for(int i=1;i<row.size();i++){
    for(int j=1;j<col.size();j++){
      int area = (row[i]-row[i-1])*(col[j]-col[j-1]);
      //cout << area << endl;
      res = max(res,area);
    }
  }
  cout << res;
   return 0;
}