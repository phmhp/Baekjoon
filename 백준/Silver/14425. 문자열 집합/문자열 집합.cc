#include <bits/stdc++.h>
using namespace std; 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    int count = 0; 
    cin >> n >> m; 
    unordered_set<string> s; 
    
    for (int i=0; i<n; i++){
        string x;
        cin >> x; 
        s.insert(x);
    }
    for (int j=0; j<m; j++){
        string q; 
        cin >> q; 
        if (s.find(q) != s.end()) count++;
    }

    cout << count; 
}

    
