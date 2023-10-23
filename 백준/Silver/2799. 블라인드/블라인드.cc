#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int M,N;
    char arr[502][502];
    int res[5]={0,};
    char ch;
    cin >> M >> N;

    for(int i=0;i<5*M+1;i++){
        for(int j=0;j<5*N+1;j++){
            cin >> ch;
            arr[i][j] = ch;
        }
    }

    // for(int i=0;i<5*M+1;i++){
    //     for(int j=0;j<5*N+1;j++){
    //         cout << arr[i][j];
    //     }
    //     cout << endl;
    // }

    int x=1, y=1;
    for(int i=1;i<5*M+1;i+=5){
        for(int j=1;j<5*N+1;j+=5){
            int cnt = 0;
            for(int k=i;k<i+4;k++){
                //cout << k << ' '  << j << endl;
                if(arr[k][j] == '*') cnt++;
            }
            if(cnt == 0)    res[0] += 1;
            else if(cnt == 1)   res[1] += 1;
            else if(cnt == 2)   res[2] += 1;
            else if(cnt == 3)   res[3] += 1;
            else    res[4] += 1;
        }
    }
    for(int i=0;i<5;i++){
        cout << res[i] << ' ';
    }
}