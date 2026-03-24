#include <bits/stdc++.h>
using namespace std;

int board[200][200];
bool vis[200][200];
int dist[200][200];
int n,m;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int main(){

    cin >> n >> m;
    string str;

    for (int i=0; i<n; i++){
        cin >> str;
        for (int j=0; j<m; j++){
            board[i][j] = str[j]-'0';
        }
    }

    queue<pair<int,int>> q ; 

    q.push({0,0});
    vis[0][0] = true; 
    dist[0][0] = 1; 
    
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        if (cur.first == (n-1) && cur.second == (m-1)) {
                cout << dist[cur.first][cur.second];
            }
        
        for (int d=0; d<4; d++){
            int nx = cur.first+dx[d];
            int ny = cur.second+dy[d];

            if (nx<0 || nx>=n || ny<0 || ny>=m) continue; 
            if (vis[nx][ny]) continue; 
            if (!board[nx][ny]) continue; 

            q.push({nx,ny});
            vis[nx][ny] = true; 
            dist[nx][ny] = dist[cur.first][cur.second]+1;

            //cout << "nx:" << nx << ", ny:" << ny <<"\n";
        }
    }
}
