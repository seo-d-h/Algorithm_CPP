#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct triple
{
    int x, y;
    char z;
}triple;

int N, M;
int a, b;
char c;

vector<triple> vec;

bool cmp(const triple & a, const triple & b){
    if(a.y == b.y){
        return a.x < b.x;
    }
    return a.y < b.y;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for(int i=0;i<M;i++){
        cin >> a >> b >> c;
        vec.push_back({a,b,c});
    }
    
    sort(vec.begin(), vec.end(), cmp);
    for(int i=0;i<M;i++){
        cout << vec[i].z;
    }
}