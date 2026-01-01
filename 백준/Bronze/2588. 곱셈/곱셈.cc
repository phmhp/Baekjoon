#include <bits/stdc++.h>
using namespace std;

int main(){
    int A,B;
    cin >> A>>B;

    cout<< A*(B%10) <<"\n"; //A*B의 1의 자리 
    cout<< A*((B/10)%10) <<"\n"; //A*B의 10의자리 
    cout<< A*((B/100)%10) <<"\n"; //A*B의 100의자리  
    cout<< (A*(B%10))+(A*((B/10)%10))*10+(A*((B/100)%10))*100 <<"\n"; //(3)+(4)*10+(5)*100
}