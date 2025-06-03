#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    int answer = 0;
    string first,second = "";
    first = to_string(a)+to_string(b);
    second = to_string(b)+to_string(a);
    if (stoi(first)>=stoi(second))
        return stoi(first);
    else return stoi(second);
}