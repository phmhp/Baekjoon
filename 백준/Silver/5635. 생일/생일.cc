#include <bits/stdc++.h>
#include <algorithm>
#include <tuple>
using namespace std;

int main()
{
    int n; 
    cin >> n;

    string oldest_name, youngest_name;
    tuple<int,int,int> oldest_ymd = {2010,12,31}, youngest_ymd={1990,1,1}; 
    
    for (int i=0; i<n; i++){
        string name;
        int d, m, y;
        cin >> name >> d >> m >> y;
        if (tie(y,m,d) < oldest_ymd) { 
            oldest_name = name, oldest_ymd = {y,m,d}; 
        }
            
        if (tie(y,m,d) > youngest_ymd) {
            youngest_name = name,youngest_ymd = {y,m,d};
        }
    }
    cout << youngest_name <<"\n";
    cout << oldest_name <<"\n";
}