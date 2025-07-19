#include <bits/stdc++.h>
using namespace std;

int main(){
    int M,N,K;
    cin >> M >> N >> K; //행,열,직사각형의 개수 
    
    vector<vector<int>> adj(M, vector<int>(N,0));
    vector<vector<bool>> visited(M,vector<bool>(N,false));
    
    for (int k =0 ; k < K;  k++){
        int lx,ly,rx,ry;
        cin >> lx >> ly >> rx >> ry ;

        for (int cury = ly ; cury<ry ; cury++){
            for (int curx= lx ; curx<rx; curx++){        
                adj[cury][curx] = 1 ;
                visited[cury][curx] = true;
            }
        }
    } //입력 및 adj 완성 

    //bfs 시작 
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,-1,0,1};

    int count = 0; 
    vector<int> areav ;
    queue<pair<int,int>> q;
    for (int i=0; i < M ; i++){
        for (int j=0; j < N ; j++){
            if (!visited[i][j]) {
                visited[i][j] = true;
                q.push({i,j});
                int area = 0; 
                count ++;
                while (!q.empty()) {
                    auto [y,x] = q.front();
                    q.pop();
                    area++;

                    for (int d=0; d<4; d++){
                        int nx = x+dx[d];
                        int ny = y+dy[d];
                        if (ny >= 0 && ny < M && nx >= 0 && nx < N && !visited[ny][nx] && adj[ny][nx] == 0){                               
                            visited[ny][nx] = true;
                            q.push({ny,nx});                                                                                    
                        }
                    }
                } 
                areav.push_back(area);
            }
        }
    }
    cout << count << "\n";
    sort(areav.begin(), areav.end());
    for (int val : areav){
        cout << val << ' ';
    }
}