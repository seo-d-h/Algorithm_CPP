#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;

struct table{
    int back_num, a, b, c, mul, sum;
};

bool cmp(const table & a, const table & b){
    if(a.mul == b.mul && a.sum == b.sum){
        return a.back_num < b.back_num;
    }
    if(a.mul == b.mul){
        return a.sum < b.sum;
    }
    return a.mul < b.mul;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    table player[n];
    for(int i=0;i<n;i++){
        cin >> player[i].back_num >> player[i].a >> player[i].b >> player[i].c;
        player[i].mul = player[i].a * player[i].b * player[i].c;
        player[i].sum = player[i].a + player[i].b + player[i].c;
    }


    sort(player, player+n, cmp);
    cout << player[0].back_num << "\n" << player[1].back_num << "\n" << player[2].back_num;
}