def solution(players, callings):
    rank = {name : i for i, name in enumerate(players)}
    
    for name in callings:
        cur = rank[name]
        prev = cur - 1 
        players[prev], players[cur] = players[cur], players[prev]
        
        rank[players[cur]] = cur
        rank[players[prev]] = prev
    return players