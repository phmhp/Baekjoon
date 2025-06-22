/* Online C++ Compiler and Editor */
#include <iostream>
#include <queue>
#include <vector> 

using namespace std;
#define X first
#define Y second 

int main() {   
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N,M;
    cin >> N >> M ; 
    vector<vector<int>> board (N, vector<int>(M));
    vector<vector<bool>> vis (N, vector<bool>(M, false));
    vector<vector<int>> dist (N, vector<int>(M, -1)); // 거리 배열 
    
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1}; //하->우->상->좌
    queue<pair<int,int>> Q;
    
    for (int n = 0 ; n < N ; n++) {
        string line;
        cin >>  line;
        for (int m = 0 ; m < M ; m++){
            board[n][m] = line[m] - '0';
        }
    }
    
    vis[0][0] = 1;
    dist[0][0] = 1; 
    Q.push({0,0});
    while (!Q.empty()){
        pair<int,int> cur = Q.front(); Q.pop();
        //cout << '(' << cur.X << ',' << cur.Y << ") -> ";
        
        if (cur.X == N-1 && cur.Y == M-1) {
            cout << dist[cur.X][cur.Y] << "\n" ;
            return 0;
        }
        for (int dir = 0 ; dir < 4 ; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M ) continue;
            if (vis[nx][ny] || board[nx][ny] != 1) continue;
            vis[nx][ny] = 1; 
            dist[nx][ny] = dist[cur.X][cur.Y] + 1; 
            Q.push({nx,ny});
        }
    }
   return 0;
}