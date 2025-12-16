#include <iostream>

using namespace std; 

int main(){
    long long n;
    cin >> n; 
/*
MenOfPassion(A[], n) {
    sum <- 0;                                   //대입 O(1)
    for i <- 1 to n - 1                         
        for j <- i + 1 to n                     //i에 따라 j 반복 횟수 달라짐 
            sum <- sum + A[i] × A[j]; # 코드1   //O(n(n-1)/2)
    return sum;
}
*/
    cout << n*(n-1)/2 << "\n";
    cout << 2 ;
    
}