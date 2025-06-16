#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string a, string b) {
    string answer = "";
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    
    int next = 0; 
    
    int n = max(a.size(), b.size());
    
    for (int i = 0; i<n; i++){
        int digitA = i < a.size() ? a[i] - '0':0;
        int digitB = i < b.size() ? b[i] - '0':0;
        
        int sum = digitA + digitB + next;
        next = sum / 10;
        answer.push_back((sum%10) + '0');
    }
    if (next>0) {answer.push_back(next+'0');}
    
    reverse(answer.begin(), answer.end());
    return answer;
}