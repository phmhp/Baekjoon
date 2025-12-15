#include <iostream>

using namespace std; 

int main(){
    long long n;
    cin >> n; 
/*
MenOfPassion(A[], n) {
    sum <- 0;                                     //대입 O(1)
    for i <- 1 to n                               //반복 O(n)
        for j <- 1 to n                           //반복 O(n)
            sum <- sum + A[i] × A[j]; # 코드1     //덧셈, 배열 접근, 곱셈 모두 O(1) 
    return sum;
}

=> 시간복잡도 n^2 
*/
    cout << n*n << "\n";
    cout << 2 ;
    
}