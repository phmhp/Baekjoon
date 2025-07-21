#include <bits/stdc++.h>
using namespace std; 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
   
    int n,c;
    cin>>n; //1부터 
    vector<bool> visited(n+1,false);
    //adj n+1만큼
    vector<vector<int>> adj(n+1,vector<int>(0));
    
    //연결 쌍 수 
    cin>>c;
    int x,y;
    for (int i=0; i<c; i++){
        cin >> x >> y; //auto[x,y]
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    

    //start=1
    queue<int> q;
    q.push(1);
    visited[1]=true;
    int count=0;
    while (!q.empty()){
        int node = q.front(); q.pop();
        for (int a:adj[node]){
            if (!visited[a]){
                q.push(a);
                visited[a]=true;
                count++;
                
            }
        }
        
    }
    cout<<count;
}