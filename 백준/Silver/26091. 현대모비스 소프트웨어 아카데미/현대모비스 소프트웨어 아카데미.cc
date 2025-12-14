#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//팀원은 두명
//팀 능력치는 M이상 (팀 능력치 = 모든 팀원의 능력치 합한 값)

//학회원 N명 
//N명으로 최대한 많은 팀 -> 최대 몇 팀 ? 
int main(){
    int N, M;
    int count = 0;
    cin >> N >> M;

    vector <int> arr(N);
    for (int i = 0 ; i<N; i++){
        cin >> arr[i];
    }
    
    //N을 두개씩 묶었을 때 M이상인 조합의 개수 
    sort(arr.begin(), arr.end());

    int srt = 0, end = N-1; 
    while (srt < end){
        if (arr[srt] + arr[end] >= M) {
            count ++;
            srt+=1;
            end-=1;
        }
        else if (arr[srt] + arr[end] < M) {
            srt+=1; 
        }
    }
    cout << count;
}

