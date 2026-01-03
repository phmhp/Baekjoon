#include <bits/stdc++.h>
using namespace std;

int main(){
    int x,y,w,h;
    cin >> x >> y >> w >> h;  
    cout<<min({abs(x),abs(y),abs(w-x),abs(h-y)});
}