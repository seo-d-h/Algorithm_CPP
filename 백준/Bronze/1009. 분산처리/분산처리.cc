#include <iostream>
#include <cmath>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, a,b,tmp=1;
    cin >> T;

    for(int i=0;i<T;i++){
        cin >> a >> b;
        for(int j=0;j<b;j++){
            tmp = (tmp*a)%10;
            //cout << "tmp : " << tmp << endl;
        }
        if(tmp == 0){
            cout << 10 << "\n";
        }
        else{
            cout << tmp << "\n";
        }
        tmp = 1;
    }
}

