#include <bits/stdc++.h>
using namespace std; 

int main(){
    int a = 'a';
    vector<int> cnt(26,0);
    
    string str;
    cin >> str; 
    for (int i=0; i<str.size(); i++){
        cnt[str[i]-a] ++;
    }

    for (int j=0; j<26; j++){
        cout << cnt[j] << " "; 
    }
    
}