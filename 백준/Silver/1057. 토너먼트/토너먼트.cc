#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, a, b, cnt=1;
    cin >> N >> a >> b;
    while(1){
        if(a == b || (a == 1 && b == 2) || (a == 2 && b == 1)) break;
        
        if(a%2==1){
            a = a/2+1;
        }
        else{
            a /= 2;
        }
        if(b%2==1){
            b = b/2+1;
        }
        else{
            b /= 2;
        }
        //cout << "a : " << a << ", b : " << b << endl;
        cnt++;
    }
    if(a == b) cnt--;
    cout << cnt;
}