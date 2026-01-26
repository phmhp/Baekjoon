#include <bits/stdc++.h>
using namespace std; 

int n;
vector<int> cnt(2, 0);
vector<vector<int>> arr;

void reg(int x, int y, int size){
    bool flag = true;
    
    //white = 0, blue = 1
    int color = arr[x][y];
    
    for (int i=x; i<x+size; i++){
        for (int j=y; j<y+size; j++){
            if (arr[i][j] != color) {
                flag = false; 
                break; 
            }
        }
       if (!flag) break; 
    }
    
    if (!flag) {
        reg(x,y,size/2);
        reg(x+(size/2), y,size/2);
        reg(x+(size/2), y+(size/2), size/2);
        reg(x,y+(size/2), size/2);
    }
    else if (flag) cnt[color] ++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //입력 
    cin >> n; 
    arr.resize(n);

    for (int i=0; i<n; i++){
        arr[i].resize(n);
        for (int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }

    reg(0, 0, n);
    
    cout << cnt[0] << "\n" << cnt[1]; 
}