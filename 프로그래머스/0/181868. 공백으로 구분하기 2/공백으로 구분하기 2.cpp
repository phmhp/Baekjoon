#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> solution(string my_string) {
    vector<string> answer;
    
    for(int i = 0; i<my_string.size(); ){
        if (my_string[i] != ' ') {
            int j = i;
            while (j < my_string.size() && my_string[j] != ' ') {
                j ++; } 
            answer.push_back(my_string.substr(i,j-i)); 
            i = j;  
        }
        else {i++;}          
    
    }
    return answer;
}