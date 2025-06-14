#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> arr1, vector<int> arr2) {
    int answer = -1;
    if (arr1.size() != arr2.size()){
        if (arr1.size()>arr2.size()) {
            answer = 1;
        }
        else {answer = -1;}
    }
    else {
        int all1=0, all2=0;
        for (int one : arr1) {all1+=one;}
        for (int two : arr2) {all2+=two;}
        
        (all1 > all2? answer = 1 : (all1 < all2?answer = -1: answer = 0));
    } 
    return answer;
}