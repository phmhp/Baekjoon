#include <bits/stdc++.h>
using namespace std; 

/*
물에 잠기지 않는 안전한 영역이 최대로 몇 개가 만들어지는지
특정 높이를 만족못하는 영역의 개수 ( h>= adj[x][y] )
*/
vector<vector<int>> adj ; 
vector<vector<bool>> visited;  
queue <pair<int,int>> q; 


int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    int n=0, nx=0, ny=0; 
    int temp_area=0, max_area=0; 
    int row_max=INT_MIN , total_max=INT_MIN; 
    int row_min=INT_MAX , total_min=INT_MAX; 
    
    cin >> n ;  

    
    adj.resize(n, vector<int>(n,0));
    visited.resize(n, vector<bool>(n, false));
    
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            cin >> adj[i][j]; 
        }
    }

    /*max_num부터 차례대로 -- 해서 알아내기 */
    for (const auto& row : adj){
        row_max = *max_element(row.begin(), row.end());
        row_min = *min_element(row.begin(), row.end());
        total_max = max(row_max, total_max);
        total_min = min(row_min, total_min);
    }

    int x, y ; 
    //bfs 
    vector<int> dx = {1,0,-1,0};
    vector<int> dy = {0,1,0,-1};
    
    for (int h = 0 ; h < total_max ; h++){

        //h 변경 후 visited (재)초기화 
        for (int c = 0 ; c<n ; c++){
            fill(visited[c].begin(), visited[c].end(), false);
        }
        temp_area = 0; 
        
        for (int k = 0 ; k < n ; k++) {
            for (int l = 0 ; l < n ; l++){
                if (!visited[k][l] and adj[k][l] > h) {
                    temp_area += 1;
                    
                    q.push({k,l});
                    visited[k][l] = true;
                    
                    while (!q.empty()){
                        tie (x,y) = q.front(); q.pop();
                        for (int d = 0 ; d<4 ; d++){
                            nx = x+dx[d];
                            ny = y+dy[d];
                            
                            if (nx>=0 and nx<n and ny>= 0 and ny<n and !visited[nx][ny] and adj[nx][ny] > h) {
                                q.push({nx,ny});
                                visited[nx][ny] = true ;
                            }
                            
                        }
                    }
                }
            }
        }
    if (max_area < temp_area) {
        max_area = temp_area; 
        
    }
        
    }
    cout << max_area;    
}