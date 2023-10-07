#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(1){
        int a, b ,c;
        cin >> a >> b >> c;
        if(a == 0 && b == 0 && c == 0) return 0;
        vector<int> vec;
        vec.push_back(a);
        vec.push_back(b);
        vec.push_back(c);
        sort(vec.begin(), vec.end());
        if(vec[2] >= vec[0]+vec[1]){
            cout << "Invalid\n";
            continue;
        }
        if(a == b && b == c){
            cout << "Equilateral\n";
            continue;
        }
        else if((a == b && b != c) || (a == c && c != b) || (b==c && c!=a)){
            cout << "Isosceles\n";
        }
        else if(a != b && b != c && a != c){
            cout << "Scalene\n";
        }
    }
}