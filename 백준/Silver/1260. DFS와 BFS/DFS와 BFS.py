from collections import deque

def dfs(srt): 
    stack = []
    visited = [False for _ in range(N+1)]
    
    his = []
    
    stack.append(srt)
    
    while stack:
        node = stack.pop()
        if visited[node]: continue 
        visited[node] = True 
        his.append(node)
        
        for n in reversed(graph[node]):
            if not visited[n] : 
                stack.append(n)
                
    print(*his) 
        
        
def bfs(srt):
    queue=deque()
    visited = [False] * (N+1)
    his = []
    
    queue.append(srt)
    his.append(srt)
    while queue:
        node = queue.popleft()
        #if visited[node] : continue 
        visited[node] = True
        
        for n in (graph[node]):
            if visited[n] : continue
            visited[n] = True
            queue.append(n)
            his.append(n)
    print(*his)
                

N,M,V = map(int,input().split()) #N:정점의 개수, M:간선의 개수,V:탐색 시작 정점 번호 
graph = [[] for _ in range(N+1)] #양방향 그래프 


for m in range(M):
    p1,p2 = map(int,input().split())
    graph[p1].append(p2)
    graph[p2].append(p1)

for g in range(1,N+1):
    graph[g].sort()

cur = V 
dfs(cur)
bfs(cur)