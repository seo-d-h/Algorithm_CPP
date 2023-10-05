#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int l,c;
int check[1001];
vector<char> vec;
vector<char> tmp;
vector<string> res;

void DFS(int x, vector<char> tmp, bool flag1, int cnt){
    if(!tmp.empty() && tmp.back() > vec[x]) return;
    if(vec[x] == 'a'|| vec[x] == 'e' || vec[x] == 'i' || vec[x] == 'o' || vec[x] == 'u') flag1 = 1;
    else cnt++;
    tmp.push_back(vec[x]);
    if(tmp.size() == l && flag1 && cnt >= 2){    // 결과 추가
        for(auto a : tmp){
            cout << a;
        }
        cout << endl;
        return;
    }
    for(int i=0;i<c;i++){
        if(check[i]) continue;
        check[i] = 1;
        DFS(i, tmp, flag1, cnt);
        check[i] = 0;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    char ch;
    cin >> l >> c;
    for(int i=0;i<c;i++){
        cin >> ch;
        vec.push_back(ch);
    }    
    sort(vec.begin(),vec.end());
    for(int i=0;i<c;i++){
        fill(check, check+1001, 0);
        check[i] = 1;
        DFS(i, tmp,0,0);
    }
}