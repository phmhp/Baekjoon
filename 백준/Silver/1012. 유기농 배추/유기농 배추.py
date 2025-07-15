from collections import deque
T = int(input())
for t in range(T):
    M,N,K = list(map(int,input().split())) #M이 열, N이 행 
    adj = [[False]*M for _ in range(N)]
    visited = [[False]*M for _ in range(N)]
    count = 0
    queue = deque()
    
    dx = [1,0,-1,0]
    dy = [0,1,0,-1]
    
    loc = [tuple(map(int,input().split())) for _ in range(K)] #x,y 순으로 입력한 형태의 배열 
    for k in range(K):
        x,y = loc[k]
        adj[y][x] = True
        
    #BFS
    for i in range(N):
        for j in range(M):
            if adj[i][j] == True and not visited[i][j] : 
                queue.append([i,j])
                visited[i][j] = True 
                count += 1 
                while queue:
                    x,y = queue.popleft()
                    for d in range(4):
                        nx=x+dx[d]
                        ny=y+dy[d]
                        if 0<= nx < N and 0<= ny < M:#nx,ny 범위 
                            if adj[nx][ny] == True and not visited[nx][ny]:
                                visited[nx][ny] = True
                                queue.append((nx,ny))
    print(count)