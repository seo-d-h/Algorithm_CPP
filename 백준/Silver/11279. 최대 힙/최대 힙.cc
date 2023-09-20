#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, num;
    priority_queue<int> pq;
    cin >> n;
    while(n--){
        cin >> num;
        if(pq.empty() && num == 0){
            cout << 0 << "\n";
        }
        else if(!pq.empty() && num == 0){
            cout << pq.top() << "\n";
            pq.pop();
        }
        else if(num !=0 ){
            pq.push(num);
        }
    }
}