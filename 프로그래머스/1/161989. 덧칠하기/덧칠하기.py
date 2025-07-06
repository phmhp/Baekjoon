def solution(n, m, section): 
    #n미터의 벽, m미터의 페인트 롤러, 페인트 칠해야하는 구역 배열 section 
    answer = 0
    section = [n-1 for n in section]
    i = 0 
    
    while i < len(section):
        
        #칠한 적이 없으면 
        start = section[i]   
        end = start + m -1  
        
        if n-1 < end : 
            end = n-1 
            start = end-m+1   
        answer += 1 
        while i < len(section) and section[i] <= end :             i += 1   
            
    return answer