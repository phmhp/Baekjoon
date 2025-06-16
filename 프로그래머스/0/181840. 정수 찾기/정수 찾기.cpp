#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> num_list, int n) {
    int answer = 0;
    return (find(num_list.begin(), num_list.end(),n) != num_list.end())? 1: 0;
}