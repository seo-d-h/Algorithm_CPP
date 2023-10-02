#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string n;
    int b;
    long long res = 0;

    cin >> n >> b;

    int len = n.length();
    for(int i=0;i<len;i++){
        if(n[i] >= '0' && n[i] <= '9'){
            //cout << n[i] << " ";
            res += (n[i] - '0')*powl(b,len-i-1);
            //cout << res << endl;
        }
        else{
            res += (n[i] - 55) * powl(b,len-i-1);
            //cout << res << endl;
        }
    }
    cout << res;
}