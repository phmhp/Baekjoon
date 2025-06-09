#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> num_list, int n) {
    vector<int> front(num_list.begin(), num_list.begin()+n);
    vector<int> rear(num_list.begin()+n, num_list.end());

    rear.insert(rear.end(), front.begin(), front.end());
    return rear;
}