#include<iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main(int argc, char** argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, M;
  string name;
  map<int, string> idx_name;
  map<string, int> name_idx;

    cin >> N >> M;
    
  for(int i=1;i<=N;i++){
    cin >> name;
    idx_name.insert({i, name});
    name_idx.insert({name, i});
  }

  for(int i=0;i<M;i++){
    cin >> name;
    if(isdigit(name[0])){     // 숫자일 경우
      cout << idx_name[stoi(name)] << "\n";
    }
    else{
      cout << name_idx[name] << "\n";
    }
  }
   return 0;
}