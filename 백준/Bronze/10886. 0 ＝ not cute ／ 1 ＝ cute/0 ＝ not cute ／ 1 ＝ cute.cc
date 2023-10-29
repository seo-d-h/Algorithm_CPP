#include <iostream>
using namespace std;

int main(){
    int N, num;
    int cute=0, not_cute=0;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> num;
        if(num == 1){
            cute++;
        }
        else if(num == 0){
            not_cute++;
        }
    }
    if(cute > not_cute){
        cout << "Junhee is cute!";
    }
    else if(cute < not_cute){
        cout << "Junhee is not cute!";
    }
}