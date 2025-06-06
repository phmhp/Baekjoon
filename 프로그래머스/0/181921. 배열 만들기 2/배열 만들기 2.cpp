#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int l, int r) {
    vector<int> answer;
    for (int i = l ; i <= r; i++){
        string s = to_string(i);
        bool valid = true;
        for (char c : s) {
            if (c!='0' && c!='5') {
                valid = false;
                break;
            }
        }
        if (valid) answer.push_back(i);
    }
    if (answer.empty()) answer.push_back(-1);
    //else {
        //sort(answer.begin(), answer.end());
    //}
    return answer;
}