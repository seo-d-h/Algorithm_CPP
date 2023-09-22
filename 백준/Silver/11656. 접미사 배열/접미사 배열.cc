#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;
    vector<string> vec;

    while(!str.empty()){
        //cout << str << endl;
        vec.push_back(str);
        str.erase(str.begin());
    }
    sort(vec.begin(), vec.end());

    for(auto a : vec){
        cout << a << "\n";
    }
}