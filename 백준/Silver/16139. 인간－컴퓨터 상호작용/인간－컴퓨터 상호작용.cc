#include <bits/stdc++.h>
using namespace std; 

int main(){
    string s; 
    int q; 

    cin >> s ; 
    cin >> q ; 

    vector <string> strarr(s.size());
    strarr[0] = s[0];
    for (int j=1; j<s.size();j++){
        strarr[j] = strarr[j-1] + s[j];
    }

    vector<string> slice(q);
    
    for (int i=0; i<q; i++){
        char c; 
        int b,e; 
        cin >> c >> b >> e; 
        if (b==0) slice[i] = strarr[e];
        else {
            slice[i] = strarr[e].substr(b,e-b+1);
        }

        cout << count(slice[i].begin(), slice[i].end(), c) << "\n";
    }
    
}