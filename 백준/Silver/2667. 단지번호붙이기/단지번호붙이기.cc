#include <bits/stdc++.h>
using namespace std; 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;

    vector<vector<bool>>visited(N,vector<bool>(N,false));
    vector<vector<int>>adj(N,vector<int>(N,0));

    string line; 
    for (int i = 0; i < N; i++){
        cin >> line;
        for (int j=0; j< N; j++){
        adj[i][j] = line[j] - '0'; 
        }
    }
    /*for (vector<int> adji : adj){
    for (int a : adji) {
        cout << a << " ";
        }cout << "\n";
    }*/
                
    queue<pair<int,int>> q;
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    int count = 0;
    vector<int> temparr;
    
    for (int x=0;x<N;x++){
        for (int y=0;y<N;y++){
            if (adj[x][y] == 1 and !visited[x][y]){
                q.push({x,y});
                //cout << x<<","<<y<<"\n";
                visited[x][y] = true; 
                count ++; 
                //cout << count << "\n";
                int temp =0; 
                while (!q.empty()){
                    
                    pair<int,int> curr = q.front(); q.pop();
                    int a = curr.first;
                    int b = curr.second;
                    
                    temp ++; 
                    //cout << "curr temp " << temp <<"\n";
                    int nx,ny;
                    for (int d = 0; d<4; d++){
                        
                        nx = a+dx[d];
                        ny = b+dy[d];

                        if (0<=nx and N>nx and 0<=ny and N>ny and adj[nx][ny] == 1 and !visited[nx][ny]){
                            q.push({nx,ny});
                            visited[nx][ny] = true; 
                        
                        }
                    }
                    
                }
                //cout << temp <<"\n";
                temparr.push_back(temp);
            }
                
        }
    }
cout << count<<"\n";
sort(temparr.begin(), temparr.end());

    for (int t : temparr) {
    cout << t << "\n";
}
}
