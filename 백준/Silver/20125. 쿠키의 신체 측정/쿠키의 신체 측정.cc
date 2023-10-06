#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    bool flag = false;
    int heart_x = 0, heart_y = 0;
    char cookie[1002][1002];
    char ch;
    cin >> N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin >> ch;
            cookie[i][j] = ch;
            if(!flag && ch == '*'){
                heart_x = i+1;
                heart_y = j;
                flag = true;
            }
        }
    }

    // 왼팔 구하기
    int left_arm=0;
    for(int i=1;i<heart_y;i++){
        if(cookie[heart_x][i] == '*') left_arm++;
    }

    // 오른팔 구하기
    int right_arm=0;
    for(int i=heart_y+1;i<=N;i++){
        if(cookie[heart_x][i] == '*') right_arm++;
    }

    // 허리 구하기
    int hury = 0;
    for(int i=heart_x+1;i<N;i++){
        if(cookie[i][heart_y] == '*') hury++;
    }

    // 왼다리 구하기
    int left_leg=0;
    for(int i=heart_x+hury;i<=N;i++){
        if(cookie[i][heart_y-1] == '*') left_leg++;
    }

    // 오른다리 구하기
    int right_leg=0;
    for(int i=heart_x+hury;i<=N;i++){
        if(cookie[i][heart_y+1] == '*') right_leg++;
    }


    cout << heart_x << " " << heart_y << "\n";
    cout << left_arm << " " << right_arm << " " << hury << " " << left_leg << " " << right_leg;

}