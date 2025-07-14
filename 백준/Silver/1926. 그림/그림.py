from collections import deque

#가로/세로 연결 -> 연결
#그림에 포함된 1의 개수 

#입력 
N,M = map(int, input().split())
adj = [list(map(int, input().split())) for _ in range(N)]
max_area = 0 
count = 0 

# for n in range(N):
#     adj[n] = list[map(int,input().split())]

#그림의 넓이 
dx = [1,0,-1,0]
dy = [0,1,0,-1]
visited = [[False] * M for _ in range(N)]
queue = deque()
for i in range(N):
    for j in range(M):
        if adj[i][j] == 1 and not visited[i][j]:
            queue.append([i,j])
            visited[i][j] = True 
            count += 1
            area = 1 
            while queue:
                x,y = queue.popleft()
                for d in range(4):
                    nx = dx[d]+ x
                    ny = dy[d]+ y
                    if nx < 0 or nx >= N or ny < 0 or ny >= M : continue 
                    if not visited[nx][ny] and adj[nx][ny] == 1 : 
                        queue.append([nx,ny])
                        visited[nx][ny] = True
                        area += 1
            max_area = max(area,max_area)

print(count)
print(max_area)
    