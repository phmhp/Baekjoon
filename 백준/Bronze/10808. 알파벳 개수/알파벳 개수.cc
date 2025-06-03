#include <iostream>
#include <array>
using namespace std;

int  main (){
    string S = "";
    cin >> S;
    array<int, 26> element = {};
    
    for (auto e : S){    
        element[int(e)-int('a')] += 1;        
    }
    for (int i = 0; i<element.size(); i++) cout<<element[i]<<" ";

    return 0;}