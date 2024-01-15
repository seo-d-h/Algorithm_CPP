#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int N, res=0;
char ch;
stack<int> s1;
stack<int> s2;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for(int i=0;i<N;i++){
        cin >> ch;
        if(ch == 'L'){
            s1.push('L');
        }
        else if(ch == 'S'){
            s2.push('S');
        }
        else if(ch == 'R'){
            if(!s1.empty()){
                res++;
                s1.pop();
            }
            else break;
        }
        else if(ch == 'K'){
            if(!s2.empty()){
                res++;
                s2.pop();
            }
            else break;
        }
        else if(ch >= '1' && ch <= '9') res++;
    }
    cout << res;
}