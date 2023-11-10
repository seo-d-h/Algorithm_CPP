#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits.h>
using namespace std;

int A, P, cnt=0;
int visited[1000000];

void self(int n){
    //cout << n << endl;
    int tmp=0;
    while(n != 0){
        tmp += pow((n%10), P);
        n /= 10;
    }
    visited[tmp]++;
    if(visited[tmp] >= 3) return;
    //cnt++;
    self(tmp);
}

int main(){
    vector<int> vec(1000000);
    cin >> A >> P;
    visited[A]++;

    self(A);
    for(int i=1;i<=1000000;i++){
        if(visited[i] == 1){
            //cout << i << endl;
            cnt++;
        }
    }

    cout << cnt;
}