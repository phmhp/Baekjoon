#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<string> solution(string myString) {
    vector<string> answer;
    int pos = -1;
    string temp="";
    for (int i = 0; i < myString.size();i++){
        if ( myString[i] != 'x'){
            temp += myString[i];          
        } 
        else if (myString[i] == 'x' && temp != "" ) {
            answer.push_back(temp);
            temp = "";
        }
    }
     if (!temp.empty())    
{         answer.push_back(temp);          
         }
     
    sort(answer.begin(), answer.end());
    return answer;
}