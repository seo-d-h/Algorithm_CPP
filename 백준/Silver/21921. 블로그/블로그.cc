#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, X;
    int day[250002];
    long long summa[250002];
    long long maxi=0;
    int cnt = 0;
    cin >> N >> X;

    for(int i=1;i<=N;i++){
        cin >> day[i];
    }

    summa[0] = 0;
    for(int i=1;i<=N;i++){
        summa[i] = summa[i-1]+day[i];
    }

    for(int i=X;i<=N;i++){
        maxi = max(maxi, summa[i] - summa[i-X]);
    }
    if(maxi == 0){
        cout << "SAD";
        return 0;
    }

    for(int i=X;i<=N;i++){
        if((summa[i] - summa[i-X]) == maxi){
            cnt++;
        }
    }
    cout << maxi << "\n" << cnt;
    
    return 0;
}