#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M;
    int arr[10002];
    cin >> N >> M;
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }

    int start_idx=0, end_idx=0, cnt=0;
    long long summa = arr[start_idx];
    while(start_idx != N){
        if(end_idx > N-1){
            end_idx = N-1;
            summa -= arr[start_idx];
            start_idx++;
        }
        //cout << start_idx << ' ' << end_idx << ' ' << summa <<  endl;
        if(summa == M){
            cnt++;
            end_idx++;
            summa += arr[end_idx];
        }
        else if(summa < M){
            end_idx++;
            summa += arr[end_idx];
        }
        else if(summa > M){
            summa -= arr[start_idx];
            start_idx++;
        }
    }
    cout << cnt;
}