#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false); //C입출력 방식 사용제한
    cin.tie(NULL);	//앞에서 cout으로 출력을 한다면 출력전에 입력부터 진행
    
    int a[1000005];
    int N;

    cin >> N;
    a[1] = 0;
    for(int i=2;i<=N;i++){
        a[i] = a[i-1]+1;
        if(i % 2 == 0){
            a[i] = min(a[i],a[i/2]+1);
        }
        if(i % 3 == 0){
            a[i] = min(a[i],a[i/3]+1);
        }    
    }
    cout << a[N];
}