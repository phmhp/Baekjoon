#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,x;
    int cnt = 0; 
    cin >> n; 
    vector<int> nums (n,0);
    for (int i=0; i<n; i++){
        cin >> nums[i];
    }
    cin >> x;

    sort(nums.begin(), nums.end());
    int head=0, tail=n-1;
    while(head<tail) {
        if (nums[head] + nums[tail] == x) {     
            cnt ++; 
            head++;
            tail--;
        }
        else if (nums[head] + nums[tail] > x) {
            tail--;
        }
        else if (nums[head] + nums[tail] < x) {
            head++;
        }
    }
    cout << cnt;
    
    
}