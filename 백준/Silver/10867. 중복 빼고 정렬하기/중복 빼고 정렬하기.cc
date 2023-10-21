#include <iostream>
#include <set>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, num;
    set<int> st;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> num;
        st.insert(num);
    }
    for(int i : st){
        cout << i << ' ';
    }
}