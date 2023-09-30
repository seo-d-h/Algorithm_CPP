#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, num, cmp, tmp=0, cnt=0;
    stack<int> stk,stk2;
    cin >> n;
    while(n--){
        cin >> num;
        stk.push(num);
    }
    cmp = stk.top(); stk.pop();
    stk2.push(cmp);
    //cout << cmp << endl;
    cnt++;
    while(!stk.empty()){
        tmp = stk.top(); stk.pop();
        if(tmp > stk2.top()) stk2.push(tmp);
    }
    cout << stk2.size();
}