#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,M;
vector<int> A;

void BinarySearch(int key){
    int start=0, end, mid;

    end = N-1;

    while(start <= end){
        mid = (start+end)/2;
        if(A[mid] == key){
            cout<<1<<"\n";
            return;
        }
        else if(A[mid] > key) end = mid-1;
        else start = mid+1;
    }
    cout<<0<<"\n";
}

int main(){
    ios::sync_with_stdio(false); //C입출력 방식 사용제한
    cin.tie(NULL);	//앞에서 cout으로 출력을 한다면 출력전에 입력부터 진행
    int n;
    int m;
    int cnt;
    int lt=0, rt, mid;
    
    vector<int> B;

    cin>>N;
    for(int i=0;i<N;i++){
        cin>>n;
        A.push_back(n);
    }
    sort(A.begin(), A.end());

    cin>>M;

    for(int i=0;i<M;i++){
        cin>>m;
        BinarySearch(m);
    }
}