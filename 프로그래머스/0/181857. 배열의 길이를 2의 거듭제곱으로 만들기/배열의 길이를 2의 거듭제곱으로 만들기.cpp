#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int size = arr.size();
    
    int target = 1;
    while (target < size ) {
        target *=2;
    }   
    cout << target-size;
    if (size !=target) arr.resize(target,0);
    return arr;
}