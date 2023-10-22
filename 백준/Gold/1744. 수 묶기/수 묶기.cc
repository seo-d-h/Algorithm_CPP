#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, num, zero=0, res=0;
    vector<int> under, over;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> num;
        if(num < 0){
            under.push_back(num);
        }
        else if(num == 0){
            zero++;
        }
        else if(num > 0){
            over.push_back(num);
        }
    }
    sort(under.begin(), under.end(), greater<int>());
    sort(over.begin(), over.end());

    int tmp1=0, tmp2 = 0;
    while(!over.empty()){       // 양수 처리하기
        tmp1 = over.back();
        over.pop_back();
        if(over.empty()){
            break;
        }
        tmp2 = over.back();
        over.pop_back();
        if(tmp1 == 1 || tmp2 == 1){
            res += (tmp1+tmp2);
        }
        else{
            res += tmp1*tmp2;
        }
        tmp1 = 0; tmp2 = 0;
    }

    int utmp1=0, utmp2=0;
    while(!under.empty()){      // 음수 처리하기
        utmp1 = under.back();
        under.pop_back();
        if(under.empty()){
            break;
        }
        utmp2 = under.back();
        under.pop_back();
        res += utmp1*utmp2;
        utmp1=0, utmp2=0;
        //cout << "res : " << res << endl;
    }
    if(utmp1 != 0 && zero != 0){
        utmp1 = 0;
    }
    else if(utmp1 != 0 && zero == 0 && tmp1 != 0){
        res += tmp1+utmp1;
        tmp1 = 0;
    }
    else if(utmp1 != 0 && zero == 0 && tmp1 == 0){
        res += utmp1;
    }
    if(tmp1 != 0){
        res += tmp1;
    }
    cout << res;

}