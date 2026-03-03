#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> cnt(10, 0);
    long long a,b,c;
    cin >> a >> b >> c;
    long long total = a*b*c;
    //cout << total; 
    string s = to_string(total);

    
    for (int i=0; i<s.size(); i++){
        cnt[s[i]-'0']++;
     }

    for (int j=0; j<10; j++){
        cout << cnt[j] <<"\n";
    }
}