#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, cnt = 0;
    
    cin >> n;

    int begin_p = 1;
    int end_p=1;
    int summ = 1;

    while(end_p != n){
        //cout << begin_p << " " << end_p << endl;
        if(summ < n){
            end_p++;
            summ += end_p;
        }
        else if(summ > n){
            summ -= begin_p;
            begin_p++;
        }
        else{
            //cout << summ << " ";
            cnt++;
            end_p++;
            summ += end_p;
        }
    }
    cout << cnt+1;
}