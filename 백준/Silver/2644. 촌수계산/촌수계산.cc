#include <bits/stdc++.h>
using namespace std;

int n, a, b, m;
int answer = -1; 
vector<vector<int>> adj; 
vector<bool> visited;

//7->2->1->3 
int dfs(int node,int depth){
    visited[node] = true;
    if (node == b) {
        answer = depth ; 
        return 1;
    }
    
    for (int next : adj[node]) {
        if (!visited[next]) {
            dfs(next,depth+1);
        }
    }
    return 1;
}

int main () {
    int x,y;

    cin >> n; //총 인원  
    adj.resize(n+1);
    visited.resize(n+1,false);
    cin >> a >> b; //촌수를 계산해야 하는 사람 a, b
    cin >> m; //부모 자식들 간의 관계의 개수     

    //adj 
    for (int i = 0 ; i< m ; i++){
        cin >> x >> y; 
        adj[x].push_back(y);
        adj[y].push_back(x);
    }  

    //시작점 a, 도착점 b
    dfs(a, 0);

    cout << answer ; 
}
