#include <string>
#include <vector>
#include <numeric>
using namespace std;

vector<int> solution(int start_num, int end_num) {
    int size = start_num - end_num +1;
    vector<int> answer(size);
    iota(answer.end(), answer.begin(), start_num);
    return answer;
}