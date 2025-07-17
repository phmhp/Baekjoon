from collections import deque

# Max = 300 
# Min = 4 
T = int(input())
for t in range(T):
    size = int(input())
    x, y = map(int,input().split())
    nx, ny = map(int,input().split())
    
    adj = [[-1]*size for _ in range(size)]
    visited = [[False]*size for _ in range(size)]

    queue = deque()
    queue.append((x,y))
    visited[x][y] = True 
    adj[x][y] = 0
    
    dir = [(2,1),(2,-1),(-2,1),(-2,-1),
           (1,2),(-1,2),(1,-2),(-1,-2)] #x,y 순 

    while queue:
        x,y = queue.popleft()
        for dx,dy in dir : 
            cx = x + dx
            cy = y + dy
            
            if 0>cx or size<=cx or 0>cy or size<=cy or visited[cx][cy]: continue  
            
            if not visited[cx][cy] and adj[cx][cy] == -1 :
                visited[cx][cy] = True
                adj[cx][cy] = adj[x][y]+1
                
                queue.append((cx,cy))
        
                if (cx,cy) == (nx,ny) : 
                    queue.clear()
                    break 
            
    print(adj[nx][ny])
            