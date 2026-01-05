#include <iostream>
#include <vector>
using namespace std; 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,op; 
    vector <int> starr; 
    cin >> n; 
    
    for (int i=0; i<n; i++){
        cin >> op;
        switch (op){
            case 1: {
                int x;
                cin >> x; 
                starr.push_back(x);
                break ; 
            }
            case 2: {
                if (starr.empty()) cout << -1 << "\n";
                else {
                    cout << starr.back() << "\n";
                    starr.pop_back(); 
                     }
                break;     
                }
            case 3: {
                cout << starr.size() << "\n"; 
                break;
            }
            case 4: {
                if (starr.empty()) cout << 1 << "\n";
                else cout << 0 << "\n";
                break; 
            }
            case 5: {
                if (!starr.empty()) cout << starr.back() << "\n";
                else cout << -1 << "\n";
                break;
            }
        }
    }
}