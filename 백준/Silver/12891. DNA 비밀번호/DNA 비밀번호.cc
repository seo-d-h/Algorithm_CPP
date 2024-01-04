#include<iostream>
#include<string>
#include<deque>
using namespace std;

int S, P, res=0;
int pw[4];
string DNA;
deque<char> tmp;
int cnt_A=0, cnt_C=0, cnt_G=0, cnt_T=0;

bool check(){
    //cout << cnt_A << " " << cnt_C << " " << cnt_G << " " << cnt_T << endl;
    //cout << pw[0] << pw[1] << pw[2] << pw[3] << endl;
    if((cnt_A >= pw[0]) && (cnt_C >= pw[1]) && 
        (cnt_G >= pw[2]) && (cnt_T >= pw[3])) return true;
    else return false;
}

void sliding_window(){
    for(int i=0;i<P;i++){
        tmp.push_back(DNA[i]);
        if(DNA[i] == 'A'){
            cnt_A++;
        }
        else if(DNA[i] == 'C'){
            cnt_C++;
        }
        else if(DNA[i] == 'G'){
            cnt_G++;
        }
        else{
            cnt_T++;
        }
    }
    if(check()) res++;
    for(int i=1;i<=S-P;i++){
        char erase = tmp.front();
        if(erase == 'A'){
            cnt_A--;
        }
        else if(erase == 'C'){
            cnt_C--;
        }
        else if(erase == 'G'){
            cnt_G--;
        }
        else{
            cnt_T--;
        }
        tmp.pop_front();
        tmp.push_back(DNA[P+i-1]);
        if(DNA[P+i-1] == 'A'){
            cnt_A++;
        }
        else if(DNA[P+i-1] == 'C'){
            cnt_C++;
        }
        else if(DNA[P+i-1] == 'G'){
            cnt_G++;
        }
        else{
            cnt_T++;
        }
        if(check()) res++;
        //cout << res << endl;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> S >> P;
    cin >> DNA;
    for(int i=0;i<4;i++){
        cin >> pw[i];
    }
    sliding_window();
    cout << res;
}