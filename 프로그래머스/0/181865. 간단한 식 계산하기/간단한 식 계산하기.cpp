#include <string>
#include <vector>

using namespace std;

int solution(string binomial) {
    int answer = 0;
    
    int pos = binomial.find(' ');
    int a = stoi(binomial.substr(0, pos));
    char op = binomial[pos+1];
    int b = stoi(binomial.substr(pos+2));
    
    switch (op){
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
    }
            
    
    return answer;
}