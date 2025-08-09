#include <bits/stdc++.h>
using namespace std; 
#define Bits 20


int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int m,x;
    unsigned int S=0; 
    string oper; 
 
    cin >> m;
    for (int i = 0; i<m; i++){
            cin >> oper;    
        
            if (oper == "add"){
                cin >> x; 
                S |= 1<<(x-1); 
            }
            else if (oper == "remove"){
                cin >> x; 
                S &= ~(1 << (x-1));
            }
            else if (oper == "check") {
                cin >> x;
                cout << ((S >>(x-1) & 1)? 1 : 0) << "\n";  
            }
            else if (oper == "toggle"){
                cin >> x; 
                S ^= 1 << (x-1);
            }
            else if (oper == "all"){
                S = (1<<Bits)-1; 
            }
            else if (oper == "empty"){
                S = 0;
            }
        }    
    }
