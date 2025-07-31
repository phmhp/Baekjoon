#include <bits/stdc++.h>
using namespace std; 

int main() {
    ios::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);

    vector<int> ropes ; 
    int N,temp;  //k개의 로프, 중량 w -> 각 로프는 모두 고르게 w/k 중량 
    int min_num=0, result=0, max_num=0; 
    //이 로프들로 들어올릴 수 있는 물체의 최대 중량 (모든 로프 사용X, 임의로 몇개의 로프)
    cin >> N; 
    for (int i = 0 ; i< N ; i++) { 
        cin >> temp ; 
        ropes.push_back(temp); 
    }
    max_num = *max_element(ropes.begin(), ropes.end());

    sort(ropes.begin(), ropes.end()); 
    min_num = *min_element(ropes.begin(), ropes.end());
    for (int j= N-1; j>=0; j--){
        
        result = ropes[j]*(N-j); //3-2, 3-1, 3-0 => 1,2,3 
           
        if (max_num < result) {
            max_num = result; 
        }
    }

    cout << max_num;
    //cout << *max_element(*min_element(ropes) * N , *max_element(ropes));
}