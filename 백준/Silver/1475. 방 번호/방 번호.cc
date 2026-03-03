#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; 
    vector<int> cnt(10,0);
    cin >> n; 
    string nstr = to_string(n);
    for (int i=0; i<nstr.size(); i++){
        cnt[nstr[i]-'0']++;
    }
    cnt[6] += cnt[9];
    cnt[6] = (cnt[6]+1) / 2;
    cnt[9] = 0;
    
    cout<< *max_element(cnt.begin(), cnt.end());

    
    
}