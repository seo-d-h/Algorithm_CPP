#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, num;
    int dasom=0;
    int cnt=0;
    int tmp=0;
    bool flag = false;
    priority_queue<int, vector<int>, less<int>> pq;
    cin >> n;

    for(int i=0;i<n;i++){
        cin >> num;
        if(flag == false){
            dasom = num;
            flag = true;
            continue;
        }
        
        pq.push(num);
        
    }

    if(!pq.empty()){
        while(dasom <= pq.top()){
        cnt++;
        dasom++;
        tmp = pq.top();
        pq.pop();
        pq.push(tmp-1);
        //cout << pq.top() << endl;
        }
    }
    
    cout << cnt;
}