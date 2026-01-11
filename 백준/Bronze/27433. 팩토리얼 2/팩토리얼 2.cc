#include <bits/stdc++.h>
using namespace std ;

int main(){
    long long n, total =1; 
    cin >> n; 

    if (n!= 0) {
        for (int i=1; i<=n; i++){
            total *= i;
        }
    }
    
    cout << total; 
}