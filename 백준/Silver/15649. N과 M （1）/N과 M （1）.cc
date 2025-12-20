#include <iostream>
#include <vector>
using namespace std; 

int N,M;
//수열 
vector<int> arr;
vector<bool> used; 

void dfs(int depth) {
    if (depth == M) {
        for (int i = 0 ; i<M; i++){
            cout << arr[i]<< " ";
        }
        cout << "\n"; 
    }

    else {
        for (int j=0 ; j<N; j++){
            if (!used[j]) {
                used[j] = true; 
                arr[depth] = j+1; 
    
                dfs(depth+1);
    
                used[j] = false; 
            }
        }
    }

}

int main(){
    //1부터 N까지 자연수 중 중복없이 M개를 고른 수열
    //사전 순으로 증가하는 순서로  출력 
    cin >> N >> M; 
    arr.resize(M);
    used.resize(N, false);

    dfs(0); 
    
}