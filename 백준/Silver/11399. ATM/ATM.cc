#include <bits/stdc++.h>
using namespace std; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,pi, sum=0,total = 0 ; 
    vector<int> piarr ; 

    cin >> n ; 
    while (n--) {
        cin >> pi; 
        piarr.push_back(pi);
    }
    
    sort(piarr.begin(), piarr.end());

       for (int p:piarr){
        //cout << p <<"\n";
        sum = sum+p ; 
        total += sum; 
        //cout << sum<<"\n";
       }


    cout << total;
}
