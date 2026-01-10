#include <bits/stdc++.h>
using namespace std; 

int main() {
    int n;
    cin >> n; 
    
    vector<pair<int,int>> orig; 
    orig.reserve(n);
    
    int x ; 
    for (int i=0; i<n; i++){
        cin >> x; 
        orig.push_back({x, i});
    }

    vector<int> comp;
    comp.reserve(n);
    for (int j=0; j<n; j++){
        comp.push_back(orig[j].first);
    }
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()),comp.end());
    
    vector<int> answer(n);
    for (int j=0; j<n; j++){
        int num = orig[j].first;
        answer[j] = lower_bound(comp.begin(), comp.end(), num)-comp.begin();   
    }
    
    for (int k=0; k<n; k++){
        cout << answer[k]<< " ";
    }
}