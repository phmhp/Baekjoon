from collections import deque

Max=100001
visited=[False]*Max
dist=[-1]*Max

N,K = map(int,input().split())
node=N #시작노드 
queue=deque()
queue.append(node)
dist[node]=0
visited[node]=True

while queue:
    node=queue.popleft()
    for x in [node-1,node+1,node*2]: #탐색후보(방향)
        if 0 <= x < Max and not visited[x] :
            queue.append(x)
            dist[x]=dist[node]+1
            visited[x]=True
            
            if x==K:
                break
print(dist[K])