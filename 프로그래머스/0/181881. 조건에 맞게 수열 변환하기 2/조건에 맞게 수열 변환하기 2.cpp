#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    vector<int> arrx = arr; //초기값 
    while (1) {
        vector<int> temp = arr;
        for (auto& e : arr) {
            if (e >= 50 && e % 2 == 0) {
                e /= 2;
            }  
            else if (e < 50 && e %2 != 0) {
                e = e*2+1;
            }
        
        }answer +=1;
        if (temp == arr) return answer-1; 
        arrx = arr;
    }
    return answer;
}