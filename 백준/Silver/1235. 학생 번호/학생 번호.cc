#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

int N, res=0, cnt=0, tmp, tmp2;
vector<string> vec;
vector<int> check;
string str;
bool flag=0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for(int i=0;i<N;i++){
        cin >> str;
        vec.push_back(str);
    }
    while(res++ < str.length()){
        check.clear();
        for(int i=0;i<N;i++){
            tmp = 0;
            for(int j=0;j<res;j++){
                tmp = 10*tmp + ((vec[i][str.length()-1-j]-'0'));
                //cout << vec[i][str.length()-1-j]-'0' << " ";
            }
            //cout << tmp << endl;
            check.push_back(tmp);
        }
        //cout << "N : " << res<<endl;
        sort(check.begin(), check.end());
        cnt=0;
        for(int i=0;i<N;i++){
            if(check[i] != check[i+1]) cnt++;
            //cout << check[i] << " " << check[i+1] << endl;
            if(cnt == N){
                cout << res;
                return 0;
            }
        }
    }
    return 0;
}