#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct cmp
{
    bool operator()(pair<int,int> a, pair<int,int> b)
    {
        if(a.first == b.first){
            return a.second > b.second;
        }
        return a.first > b.first;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> Q;
    int N, num;
    cin >> N;

    for(int i=0;i<N;i++){
        cin >> num;
        if(num != 0){
            Q.push({abs(num), num});
        }
        else{           // num이 0이라면
            if(Q.empty()){
                cout << "0\n";
            }
            else{
                cout << Q.top().second << "\n";
                Q.pop();
            }
        }
    }

}