#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    string x, y, z;
    cin >> x >> y;
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());

    a = stoi(x);
    b = stoi(y);
    z = to_string(a+b);
    reverse(z.begin(), z.end());
    c = stoi(z);
    cout << c;
}