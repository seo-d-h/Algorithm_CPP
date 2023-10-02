#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, num;
    string str;
    stack<double> stk;
    vector<int> vec;
    cin >> n;
    cin >> str;
    for(int i=0;i<n;i++){
        cin >> num;
        vec.push_back(num);
    }

    for(int i=0;i<str.length();i++){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            stk.push(vec[str[i] - 'A']);
        }
        else if(str[i] == '+'){
            double tmp1 = stk.top();
            stk.pop();
            double tmp2 = stk.top();
            stk.pop();
            stk.push(tmp2+tmp1);
        }
        else if(str[i] == '-'){
            double tmp1 = stk.top();
            stk.pop();
            double tmp2 = stk.top();
            stk.pop();
            stk.push(tmp2-tmp1);
        }
        else if(str[i] == '*'){
            double tmp1 = stk.top();
            stk.pop();
            double tmp2 = stk.top();
            stk.pop();
            stk.push(tmp2*tmp1);
        }
        else if(str[i] == '/'){
            double tmp1 = stk.top();
            stk.pop();
            double tmp2 = stk.top();
            stk.pop();
            stk.push(tmp2/tmp1);
        }
    }
    cout<<fixed;
    cout.precision(2);
    cout << stk.top();
}