#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int n) {
    vector<int> answer;
    int i =-1;
    (arr.size() & 1)? i = 0: i = 1;
    for (i ; i<arr.size(); i+=2){
        arr[i]+=n;
    }
    return arr;
}