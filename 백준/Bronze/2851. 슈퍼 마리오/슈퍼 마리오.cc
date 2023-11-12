#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    bool flag = false;
    int num, res=0;
    int tmp1=0, tmp2=0;
    vector<int> vec;
    for(int i=0;i<10;i++){
        cin >> num;
        vec.push_back(num);
    }

    for(int i=0;i<10;i++){
        res += vec[i];
        if(res == 100){
            flag = true;
            break;
        }
        if(res < 100){
            tmp1 = res;
            tmp2 = res;
        }
        if(res > 100){
            tmp2 = res;
            break;
        }
        //cout << "tmp1 : " << tmp1 << ", tmp2 : " << tmp2 << endl;
    }
    if(flag){
        cout << res;
    }
    else{
        if(100-tmp1 == tmp2-100){
            cout << tmp2;
        }
        else if(100-tmp1 > tmp2-100){
            cout << tmp2;
        }
        else if(100-tmp1 < tmp2-100){
            cout << tmp1;
        }
    }
}