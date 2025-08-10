#include <bits/stdc++.h>
using namespace std ; 

int main(){
    int n ; 
    string name, action ; 
    vector<string> log ; 
    cin >> n ; 
    
    unordered_set<string> inoffice; 
    
    for (int i = 0 ; i < n ; i++) {
        cin >> name >> action ; 
      
        if (action == "enter") {
            inoffice.insert(name);
        }
        else if ( action == "leave"){
            inoffice.erase(name);
        }
    }
    
    vector<string> v(inoffice.begin(), inoffice.end());
    sort(v.begin(), v.end(), greater<string>()); //unordered_set을 v에 정렬해서 넣음 
    
    for (const auto& s: v) {
        cout << s<<"\n";
    }
    
}
