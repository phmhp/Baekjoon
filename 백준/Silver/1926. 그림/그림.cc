#include <bits/stdc++.h>
using namespace std; 

int board[500][500];
bool vis[500][500];


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //변수 선언
    int cnt=0,max_area = 0; 
    int n, m; 
    int dx[] = {1,0,-1,0};
    int dy[] = {0,1,0,-1};
    
    //입력 
    cin >> n >> m;

    for (int i=0; i<n ; i++){
        for (int j=0; j<m; j++){
            cin >> board[i][j];
        }
    }

    //start
    //bfs 
    
    queue<pair<int,int>> q;
    
    
    //vis를 기준으로 방문안한 노드가 없어야함 
    for (int a=0; a<n; a++){
        for (int b=0; b<m; b++){
            
            if (board[a][b]==0) continue; 
            if (vis[a][b]) continue; 
             
            cnt ++; 
            
            
            q.push({a,b});
            vis[a][b]=true;      
            
             
            //cout << "cnt++ count : " <<cnt << "|"<< a<<","<<b<<'\n';
            int tarea=1;
            while (!q.empty()){
                    
                    auto cur = q.front();
                    q.pop();

                    for (int dir = 0; dir < 4; dir++){
                        int nx = cur.first+dx[dir];
                        int ny = cur.second+dy[dir];

                        
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if (!board[nx][ny]) continue;
                        if (vis[nx][ny]) continue;  
                        
                        
                        q.push({nx,ny});
                        vis[nx][ny] = true;
                        tarea++;
                        //cout << "tarea : "<< tarea <<"|"<<"nx,ny = "<<nx<<","<<ny<<"\n";
                    }
                }

                if (max_area <tarea) max_area = tarea ; 
            
        }
    }
    




    //출력 
    cout << cnt <<"\n"; 
    cout << max_area;
}