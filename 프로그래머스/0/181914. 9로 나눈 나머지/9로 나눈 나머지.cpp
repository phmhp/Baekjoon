#include <string>
#include <vector>

using namespace std;

int solution(string number) {
    int answer = 0;
    for (auto e : number){
        answer += e-'0';
    }
    return answer % 9 ;
}