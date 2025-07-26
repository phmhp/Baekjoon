#include <bits/stdc++.h>
using namespace std; 

string message = "use the stairs";
int answer = -1;
int F,S,G,U,D; 
//범위 체크 F 
//시작 노드 S, 도착 노드 G
//이동 : U 버튼 : 위로 U층, D버튼: 아래로 D층 
vector<bool> visited; 
queue<pair<int,int>> q; 

int dfs (int node, int depth){
    visited[node] = true;  
    if (node == G) {
        answer = depth; 
    }
    
    vector<int> pos = {node+U, node-D};
    
    for (int next : pos){
        if ( next < F+1 and next > 0 and !visited[next]) {
            //cout << next << "\n" ;
            dfs(next,depth+1);
            
        }
    }
 return -1;       
}

int bfs (int node){
    int depth = 0;
    q.push({node,depth}); 
    
   
    
    while (!q.empty()) {
        auto [node,depth] = q.front();
        q.pop();   
        visited[node] = true; 
        
        if (node == G) {
        answer = depth;
        return 0;
        }
        vector<int> pos = {node+U, node-D};
        for (int next : pos) {
            if (next > 0 and next < F+1 and !visited[next]) {
                q.push({next,depth+1});           
                visited[next] = true; 
            }
        }
        
    }
    return 0; 
}

int main(){
    cin >> F >> S >> G >> U >> D ;
    //1~F 내에서만 시도해보기 
    if (S==G) {
        cout << 0;
        return 0;
    }
    visited.resize(F+1,false);
    
    bfs(S);
    
    if (answer > -1) {
        cout << answer ; 
        return 0 ;
    }

    cout << message;
}