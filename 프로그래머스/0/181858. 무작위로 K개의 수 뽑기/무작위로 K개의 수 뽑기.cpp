#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> solution(vector<int> arr, int k) {
    vector<int> answer;
    unordered_set<int> setarr;
    
    for (int num : arr) {
        if (setarr.count(num) == 0) {
            setarr.insert(num);
            answer.push_back(num);
        }
        
    }
    

    
    answer.resize(k, -1);
    return answer;
}