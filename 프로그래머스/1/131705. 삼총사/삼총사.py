def solution(number): 
    #조합
    answer = 0
    path = []
    
    
    def combination(start):
        nonlocal answer 
        if len(path) == 3: 
            if sum(path) == 0:
                answer += 1 
            return 
        
        for i in range(start,len(number)):
            path.append(number[i])
            combination(i+1)
            path.pop()
            
    combination(0)
    return answer