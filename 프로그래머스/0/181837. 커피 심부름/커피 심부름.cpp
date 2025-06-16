#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<string> order) {
    int answer = 0;
    vector<string> americano = {"iceamericano", "americanoice","hotamericano", "americanohot","americano","anything"};
    vector<string> cafelatte = {"icecafelatte", "cafelatteice","hotcafelatte", "cafelattehot","cafelatte"};
    for (const auto& o : order) {
        if (find(cafelatte.begin(), cafelatte.end(), o)!= cafelatte.end()) {
            answer += 5000;
        }
        else {answer += 4500; }
    }
    return answer;
}