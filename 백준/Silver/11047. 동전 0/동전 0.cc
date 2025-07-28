#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<int> money;
    int N,K,price;
    int count=0; 
    cin >> N >> K;
    
    
    for (int j = 0 ; j<N; j++){
        cin >> price;
        money.push_back(price);    
    }

    for (int i = N-1; i>=0; i--){
         
        if (money[i] <= K){
            
            count += K/money[i];
            K -=(K/money[i]) * money[i];
        } 
    }
    cout << count;
}