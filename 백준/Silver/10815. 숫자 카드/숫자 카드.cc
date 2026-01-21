#include <bits/stdc++.h>
using namespace std; 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n , m, nnum, mnum; 
    cin >> n; 
    vector<int> narr(n); 
    for (int i=0 ; i<n; i++) {
        cin >> nnum;
        narr[i] = nnum; // 상근's
    }
    
    sort(narr.begin(), narr.end());
    
    cin >> m;
    vector<int> marr;
    marr.reserve(m);
    
    for (int j=0; j<m; j++) {
        cin >> mnum; // 갖고있는지 확인할 숫자

        cout << (binary_search(narr.begin(), narr.end(), mnum))<< " ";   
    }


}