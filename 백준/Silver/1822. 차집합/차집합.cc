#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main(){
    int n, m, num;
    int cnt_a=0,cnt_b=0;
    vector<int> a;
    vector<int> b;
    vector<int> res;
    cin >> n >> m;
    a.resize(n);
    b.resize(m);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<m;i++){
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for(int i=0;i<n;i++){
        if(!binary_search(b.begin(), b.end(), a[i])){
            res.push_back(a[i]);
        }
    }
    if(!res.empty()){
        cout << res.size() << "\n";
        for(auto a : res){
            cout << a << " ";
        }
    }
    else{
        cout << 0;
    }
    return 0;
}