#include <iostream>
using namespace std;

int main(){
	int a,b,c,d,res;
	cin >> a >> b >> c >> d;
	res = min(a+d, b+c);
	cout << res;
}