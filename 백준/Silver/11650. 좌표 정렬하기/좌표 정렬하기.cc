#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    
    int n;
    cin >> n; 
    vector<pair<int,int>> tr;
    tr.reserve(n);
    for (int i=0; i<n; i++){
        int x,y;
        cin >> x >> y; 
        tr.push_back({x,y});
    }

    sort(tr.begin(), tr.end());
    
    for (int j=0; j<n; j++){
        cout << tr[j].first<< " " <<tr[j].second << "\n";
    }
    
}