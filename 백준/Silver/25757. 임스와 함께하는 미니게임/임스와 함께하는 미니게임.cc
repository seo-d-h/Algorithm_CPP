#include <iostream>
#include <set>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    char game;
    string str;
    set<string> st;
    cin >> N >> game;
    while(N--){
        cin >> str;
        st.insert(str);
    }
    if(game == 'Y'){
        cout << st.size()/1;
    }
    else if(game == 'F'){
        cout << st.size()/2;
    }
    else if(game == 'O'){
        cout << st.size()/3;
    }
    // cout << st.size();
}