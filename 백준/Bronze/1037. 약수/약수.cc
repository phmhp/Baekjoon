#include <bits/stdc++.h>
using namespace std ;

int main(){
    int n; 
    cin >> n; 

    
    long long a;
    long long total = 1; 

    vector<long long> arr;
    arr.reserve(n);
    if (n==1) {
        cin >> a ; 
        cout << a * a ; 
        return 0; 
    }
    for (int i = 0; i< n; i++){
        cin >> a; 
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end()); 
    
    cout << arr[0] * arr[n-1]; 
}