#include <bits/stdc++.h>
using namespace std; 

// 동전은 총 n종류 
// 동전을 적절히 사용해서 가치의 합을 k로 만들 때, 필요한 동전 개수의 최솟값 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k; 
    int cnt = 0 ; 
    cin >> n >> k;

    vector<int> A(n); 
    for (int i=0; i<n; i++){
        int temp;
        cin >> A[i]; //오름차순으로 입력 
    }

    //출력: k원을 만드는데 필요한 동전 개수의 최솟값 
    // -> 배열을 뒤에서부터 돌면서 k보다 작은 최대 coin이 몇개씩 들어갈 수 있는지 파악  
    for (int j=n-1; j>=0; j--) {
        if (A[j] > k) continue; 
        cnt += k/A[j]; 
        k-=A[j]*(k/A[j]);

        if (k==0) break; 
    }
    cout << cnt; 
}