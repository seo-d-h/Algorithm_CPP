#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void add_func(vector<int> &vec, int x){
    vector<int>::iterator it;
    
    it = find(vec.begin(), vec.end(), x);
    if(it == vec.end()){
        vec.push_back(x);
    }
    else
        return;
}

void remove_func(vector<int> &vec, int x){
    vector<int>::iterator it;
    it = find(vec.begin(), vec.end(), x);

    if(it == vec.end()){
        return;
    }
    else
        vec.erase(remove(vec.begin(), vec.end(), x), vec.end());
}

void check_func(vector<int> &vec, int x){
    vector<int>::iterator it;
    it = find(vec.begin(), vec.end(), x);

    if(it == vec.end()){
        cout << 0 << "\n";
    }
    else
        cout << 1 << "\n";
}

void toggle_func(vector<int> &vec, int x){
    vector<int>::iterator it;
    it = find(vec.begin(), vec.end(), x);

    if(it == vec.end()){
        vec.push_back(x);
    }
    else{
        vec.erase(remove(vec.begin(), vec.end(), x), vec.end());
    }
}

void all_func(vector<int> &vec){
    vector<int>::iterator it;
    

    for(int i=1;i<=20;i++){
        it = find(vec.begin(), vec.end(), i);
        if(it != vec.end()){
            vec.erase(remove(vec.begin(), vec.end(), i), vec.end());
        }
    }
    for(int i=1;i<=20;i++){
        vec.push_back(i);

    }

}

void empty_func(vector<int> &vec){
    vector<int>::iterator it;
    

    for(int i=1;i<=20;i++){
        it = find(vec.begin(), vec.end(), i);
        if(it != vec.end()){
            vec.erase(remove(vec.begin(), vec.end(), i), vec.end());
        }
    }
}

int main(){
    ios::sync_with_stdio(false); //C입출력 방식 사용제한
    cin.tie(NULL);	//앞에서 cout으로 출력을 한다면 출력전에 입력부터 진행
    int M,n;
    string op;
    vector<int> v;

    cin >> M;

    for(int i=0;i<M;i++){
        cin >> op;
        if(op == "add"){
            cin >> n;
            add_func(v, n);
        }
        else if(op == "remove"){
            cin >> n;
            remove_func(v, n);
        }
        else if(op == "check"){
            cin >> n;
            check_func(v, n);
        }
        else if(op == "toggle"){
            cin >> n;
            toggle_func(v, n);
        }
        else if(op == "all"){
            all_func(v);
        }
        else if(op == "empty"){
            empty_func(v);
        }
    }
}