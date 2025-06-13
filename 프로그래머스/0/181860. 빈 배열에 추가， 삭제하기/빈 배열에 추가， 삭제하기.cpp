#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<bool> flag) {
    vector<int> answer;
    for (int i = 0; i<flag.size();i++){
        if (flag[i]==true) {
            int j = 0;
            while (j <arr[i]){
                answer.push_back(arr[i]);
                answer.push_back(arr[i]);
                j++;
            }
        }
        
        else {
            int k = 0;
            while (k < arr[i]) {
                answer.pop_back();
                k++;
 }
        }
    }
    return answer;
}