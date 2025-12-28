#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N, k;
    cin >> N >> k; 
    vector<int> arr(N);
    for (int i=0; i<N; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end()); 
    //뒤에서 k번째 인덱스가 커트라인점수 

    cout << arr[N-k];
}
