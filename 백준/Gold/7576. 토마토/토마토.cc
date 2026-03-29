#include <bits/stdc++.h>
using namespace std; 


int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int board[1001][1001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    queue<pair<int,int>> q; 
    int m,n; 
    cin >> m >> n; 
    //int board[n][m];//지역배열로 할당하면 스택에 잡혀서 런타임에러 가능 

    
    // 입력 
    for (int i=0; i<n; i++){
        for (int j=0;j<m;j++){
            cin >> board[i][j]; 
            
            if (board[i][j] == 1) {
                q.push({i,j});
            }
        } 
    }

    //bfs
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for (int d=0; d<4; d++){
            int nx = cur.first+dx[d];
            int ny = cur.second+dy[d];
            
            if (nx<0 || nx >= n || ny<0 || ny>=m) continue; 
            if (board[nx][ny] == -1) continue; 
            if (board[nx][ny] >= 1) continue; 

            if (board[nx][ny] == 0) {
                board[nx][ny] = board[cur.first][cur.second]+1; 
                q.push({nx,ny});
            }
        }
        
    }

    
    //끝나는 조건 
    //더이상 0이 없으면, board에서의 최대값을 출력하면 됨 
    //근데 q에 있는 것 다 처리하고나서도 0이 남아있을 수도 -> -1 출력 
    int temp;
    int mnum=0; 
    for (int k=0; k<n; k++){
        for (int l=0;l<m;l++){
            if (board[k][l] == 0) {cout << -1; return 0; }
        }
    temp = *max_element(board[k], board[k]+m);    
    if (temp > mnum) mnum = temp; 
    }

    cout << mnum-1; 
}