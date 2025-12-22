#include <iostream>
#include <vector>
using namespace std;

int N,M;
vector<int> arr;

void dfs(int depth,int start){

    if (depth==M){
        for (int i=0; i<M; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    } 
    for(int j=start;j<N;j++){
        arr[depth]=j+1;
        dfs(depth+1,j+1);
        
    }
}

int main() {
    cin >> N >> M;
    arr.resize(M,false);
    
    dfs(0,0);
}