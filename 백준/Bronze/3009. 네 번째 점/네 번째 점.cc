#include <bits/stdc++.h>
using namespace std;

int main(){
    int x_num[1001]={0};
    int y_num[1001]={0};
    int x,y ;
    int f_x, f_y;
    
    for (int i=0; i<3;i++){
      cin >> x >> y;
        x_num[x]++; 
        y_num[y]++;  
    }

    for (int j=1; j<1001; j++){
        if (x_num[j] == 1) f_x = j; 
        if (y_num[j] == 1) f_y = j;
    }
    cout << f_x << " " << f_y; 
    
}