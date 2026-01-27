#include <bits/stdc++.h>
using namespace std; 

int n; 
vector<vector<int>> arr; 
string str = "";

void reg(int x, int y, int size){
    if (size == 1) {                 // 기저 조건
        str += char('0' + arr[x][y]);
        return;
    }
    int color = arr[x][y];
    bool flag = true; 
    
    for (int i=x; i<x+size; i++){
        for (int j=y; j<y+size; j++){
            if (arr[i][j] != color) {
                flag = false;
                break; 
            }
        }if (!flag) break; 
    }

    if (!flag) {
        str= str+"(";
        reg(x,y, size/2);
        reg(x,y+size/2, size/2);
        reg(x+size/2,y, size/2);
        reg(x+size/2, y+size/2, size/2);
        str= str+ ")";
    }
    else if (flag) str+=char('0' + color); 
}
int main(){
    cin >> n; 
    
    arr.resize(n);

    for (int i=0; i<n; i++){
        string line; 
        cin >> line; 
        
        arr[i].resize(n);
        for (int j=0; j<n; j++){
           
            arr[i][j] = line[j] - '0';
        }
    }

    reg(0,0, n);

    cout << str; 
}