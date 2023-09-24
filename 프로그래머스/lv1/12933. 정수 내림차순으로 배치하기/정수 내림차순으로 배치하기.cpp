#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    int tmp=0;
    
    vector<long long> vec;
    
    while(n != 0){
        tmp = n % 10;
        vec.push_back(tmp);
        n /= 10;
    }

    sort(vec.begin(), vec.end(), greater<long long>());
    
    for(auto a : vec){
        answer = answer*10 + a;
    }
    
    return answer;
}