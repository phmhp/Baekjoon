#include <iostream>
#include <vector>
using namespace std;


//메모리 초과 -> 카운팅정렬 방식으로 풀어야함 
int main(){
    int N;
    int x;
    cin >> N;
    vector<int> cnt(10001,0);
    
    for (int i=0; i<N; i++){
        cin >> x; 
        cnt[x]++; 
    }
    
     for (int j=0; j<10001; j++){
        while (cnt[j]--) cout<< j << "\n"; 
    }
    
}