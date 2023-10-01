#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    string str;
    cin >> str;
    if(str == "A+") cout << fixed << setprecision(1) << 4.3;
    else if(str == "A0") cout <<fixed << setprecision(1) << 4.0;
    else if(str == "A-") cout <<fixed << setprecision(1) << 3.7;
    else if(str == "B+") cout << fixed << setprecision(1) <<3.3;
    else if(str == "B0") cout << fixed << setprecision(1) <<3.0;
    else if(str == "B-") cout << fixed << setprecision(1) <<2.7;
    else if(str == "C+") cout << fixed << setprecision(1) <<2.3;
    else if(str == "C0") cout << fixed << setprecision(1) <<2.0;
    else if(str == "C-") cout << fixed << setprecision(1) <<1.7;
    else if(str == "D+") cout << fixed << setprecision(1) <<1.3;
    else if(str == "D0") cout << fixed << setprecision(1) <<1.0;
    else if(str == "D-") cout << fixed << setprecision(1) <<0.7;
    else if(str == "F") cout << fixed << setprecision(1) <<0.0;
}