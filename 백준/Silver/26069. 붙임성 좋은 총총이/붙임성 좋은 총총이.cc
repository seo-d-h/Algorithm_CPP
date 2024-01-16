#include <iostream>
#include <unordered_set>
using namespace std;

int N;
string name1, name2;
unordered_set<string> us;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    us.insert("ChongChong");
    for(int i=0;i<N;i++){
        cin >> name1 >> name2;
        if(us.find(name1) != us.end()){
            us.insert(name2);
        }
        else if(us.find(name2) != us.end()){
            us.insert(name1);
        }
    }
    cout << us.size();

    return 0;
}