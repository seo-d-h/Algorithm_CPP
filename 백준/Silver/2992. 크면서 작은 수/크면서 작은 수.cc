#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string str;
int num;
int bigger=0;
vector<int> vec;
vector<int> tmp;
int visited[10];

void DFS(int start, int res, int cnt){
    if(cnt == vec.size() && res > num){
        tmp.push_back(res);
    }
    for(int i=0;i<vec.size();i++){
        if(visited[i]) continue;
        visited[i] = 1;
        DFS(i+1, res*10+vec[i], cnt+1);
        visited[i] = 0;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> str;
    num = stoi(str);
    for(int i=0;i<str.length();i++){
        vec.push_back(str[i]-'0');
    }
    DFS(0, 0, 0);
    if(tmp.empty()){
        cout << 0;
    }
    else{
        sort(tmp.begin(), tmp.end());
        // for(int a : tmp){
        //     cout << a << endl;
        // }
        cout << tmp[0];
    }
}