#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n, string control) {
    int answer = 0;
    for (char e : control){
        //cout << answer<<"→";
        if (e == 'w') n +=1;
        if (e =='s') n -=1;
        if (e =='d') n +=10;
        if (e =='a') n -=10;

    }
    return n;
}