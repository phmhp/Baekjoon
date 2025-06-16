#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> delete_list) {
    vector<int> answer;
    for (auto num : arr) {
    if (find(delete_list.begin(), delete_list.end(), num) == delete_list.end()) {
        answer.push_back(num);
        }
    }
    return answer;
}