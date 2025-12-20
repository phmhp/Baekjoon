#include <iostream>

using namespace std; 

int main(){
    long long n;
    cin >> n; 
/*
MenOfPassion(A[], n) {
    sum <- 0;
    for i <- 1 to n - 2
        for j <- i + 1 to n - 1  
            for k <- j + 1 to n    //O(n*(n-1)/4)
                sum <- sum + A[i] × A[j] × A[k]; # 코드1
    return sum;
}
*/
    cout << n*(n-1)*(n-2)/6 << "\n";
    cout << 3 ;
    
}
