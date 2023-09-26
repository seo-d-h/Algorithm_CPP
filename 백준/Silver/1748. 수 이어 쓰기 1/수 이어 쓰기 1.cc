#include <iostream>
#include <cmath>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int len=0;
    int res=0;
    int tmp = n;
    while(tmp){
        tmp /= 10;
        len++;
    }

    for(int i=1;i<len;i++){
        res += i*9*pow(10,i-1);
        //cout << res << endl;
    }
    tmp = n - pow(10,len-1);
    // cout << "len : " << len << endl;
    // cout << "tmp : " << tmp << endl;
    res += len*(tmp+1);
    cout << res;
}