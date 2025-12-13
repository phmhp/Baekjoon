#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int main(){
    int n, x, count=0; 
    cin >> n; 
    vector<int> arr(n);
    
    for (int k=0; k<n; k++){
        cin >> arr[k]; 
    }

    cin >> x; 
    
    sort(arr.begin(), arr.end());
    int i=0, j=n-1; 
    // 양끝의 원소들을 더한다
    // 더한 값이 x보다 작으면 i인덱스 +1 
    // 더한 값이 x보다 크면 j인덱스 -1 
    // 더한 값이 x와 같으면 i인덱스 +1 && j인덱스 -1
    // i 가 j보다 작아야하는 것이 반복문의 조건 

    while (i < j) {
        if (arr[i]+arr[j] == x) {
            i += 1;
            j -= 1;
            count += 1; 
        }
        else if (arr[i]+arr[j] < x) {
            i += 1;
        }
        else if (arr[i]+arr[j] > x) {
            j -= 1;
        }
    }
    
   
    cout << count;
    return 0; 
    
}