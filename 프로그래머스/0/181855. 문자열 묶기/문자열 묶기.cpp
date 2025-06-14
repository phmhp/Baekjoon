#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<string> strArr) {
    int answer = 0;
    vector<int> count(31,0);
    for (auto s : strArr){
        count[s.size()] ++;
    }
    auto it = max_element(count.begin(), count.end());
    return *it;
    //int index = distance(count.begin() ,it);
    //return index;
}