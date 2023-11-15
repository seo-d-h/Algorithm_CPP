#include<iostream>
#include<cstring>

using namespace std;

int main(int argc, char** argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  string str1, str2, res, tmp_string;
  char tmp;
  cin >> str1 >> str2;
  for(int i=0;i<str1.length();i++){
    res += str1[i];
    res += str2[i];
  }
  //cout << res << endl;
  while(res.length() != 2){
    tmp_string = "";
    for(int i=0;i<res.length()-1;i++){
      tmp = (((res[i]-'0')+(res[i+1]-'0'))%10)+'0';
      tmp_string += tmp;
    }
    res = tmp_string;
  }
  cout << res << endl;
   return 0;
}