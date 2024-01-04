#include <iostream>
#include <memory.h>
using namespace std;

int N, M, K, cnt=0, res=0;
char ch;
char arr[5002];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> ch;
            arr[j] = ch;
        }
        for(int j=0;j<K;j++){
            if(arr[j] == '0') cnt++;
        }
        //cout << "cnt : " << cnt << endl;
        if(cnt == K) res++;
        for(int j=1;j<=M-K+1;j++){
            if(arr[j-1] == '0') cnt--;
            if(arr[j+K-1] == '0') cnt++;
            if(cnt == K) res++;
            //cout << arr[j+K-1];
        }
        //cout << endl;
        memset(arr, 0, sizeof(arr));
        cnt=0;
    }
    cout << res;
}