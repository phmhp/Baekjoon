#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> adj;
vector<bool> visited;
int result = 0; 

int dfs(int node){
    visited[node]=true; 
    
    for (int a : adj[node]) {
        if (visited[a]==false) {
            dfs(a); 
        }
    }
    return 0; 
}


int main(){
    ios::sync_with_stdio(false); 
    cin.tie(0); 
    //연결 요소의 개수 구하기 
    int n, m;
    int u, v; 
    cin >> n >> m;
    adj.resize(n+1, vector<int>(n+1, 0)) ; 
    visited.resize(n+1, false);
    
    for (int  i = 0; i < m; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        //adj[u][v] = 1 ; 
        //adj[v][u] = 1 ;
    }

    for (int j =1; j < n+1; j++){
        if (visited[j] == false) {
            dfs(j);
            result+= 1 ; 
        }
        
    }

    cout << result ; 
}
