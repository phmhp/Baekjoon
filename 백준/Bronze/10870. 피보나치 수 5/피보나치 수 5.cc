#include <bits/stdc++.h>
using namespace std ;

int main(){
    int n; 
    cin >> n; 

    int cnt = 1; 
    int a = 0; 
    int b = 1; 
    int temp ; 
    while (cnt <= n){
        temp = a;
        a = b;  
        b = temp+b; 
        cnt ++; 
    }

    cout << a;
}