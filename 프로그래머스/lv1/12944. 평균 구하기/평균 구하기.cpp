#include <string>
#include <vector>
#include <iostream>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    double num=0;

    for(int i=0;i<arr.size();i++){
        num += arr[i];
    }
    answer = num / arr.size();
    return answer;
}