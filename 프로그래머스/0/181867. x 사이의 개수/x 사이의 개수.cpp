#include <string>
#include <vector>

using namespace std;

vector<int> solution(string myString) {
    vector<int> answer;

    int pos = -1;
    for (int i = 0; i<= myString.size();i++){
        if (myString[i]=='x' || myString[i]==myString.size()) {
            answer.push_back(i-pos-1);
            pos = i; }

    }
    answer.push_back(myString.size()-pos-1);
        
    return answer;
}