#include<iostream>


using namespace std;

int main(int argc, char** argv)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  int N, num;
  int a=0;
  cin >> N;
  for(int i=0;i<N*2;i++){
    cin >> num;
    a += abs(num);
  }
  cout << a;
   return 0;
}