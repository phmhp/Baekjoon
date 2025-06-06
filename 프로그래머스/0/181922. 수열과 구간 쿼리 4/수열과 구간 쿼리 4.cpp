#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;
    
    for (auto q : queries){
        int s = q[0], e = q[1], k = q[2];
        
        for (int i = q[0]; i <= q[1]; i++){
            if (i==0%q[2]) arr[i]=arr[i]+1;
        }
        cout << arr[0];
    }
    
    return arr;
}