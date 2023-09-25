#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const string& a, const string& b){
    if(a.length() != b.length()) return a.size() < b.size();
    else{
        int cnt_a = 0, cnt_b = 0;
        for(int i=0;i<a.length();i++){
            if(isdigit(a[i])) cnt_a += a[i] - '0';
            if(isdigit(b[i])) cnt_b += b[i] - '0';
        }
        if(cnt_a != cnt_b) return cnt_a < cnt_b;
        else return a < b;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string str;
    vector<string> vec;
    cin >> n;

    for(int i=0;i<n;i++){
        cin >> str;
        vec.push_back(str);
    }

    sort(vec.begin(), vec.end(), cmp);

    for(auto a : vec){
        cout << a << "\n";
    }
}