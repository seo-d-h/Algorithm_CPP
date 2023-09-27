#include <iostream>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cnt = 0, cnt_tmp=0;
    string s1, s2;
    getline(cin,s1);
    getline(cin,s2);

    for(int i=0;i<s1.length();i++){
        //cout << "i : "<< i<<endl;
        cnt_tmp = 0;
        for(int j=0;j<s2.length();j++){
            if(s1[j+i] == s2[j]){
                //cout << s1[j] << " " << s2[j] << endl;    
                cnt_tmp++;
            }
        }
        if(cnt_tmp == s2.length()){
            cnt++;
            i+=s2.length()-1;
        }
    }
    cout << cnt;
}