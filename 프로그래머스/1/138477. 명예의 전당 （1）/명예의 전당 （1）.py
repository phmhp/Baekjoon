def solution(k, score):
    answer = []
    result = []
    answer.append(score[0])
    result.append(score[0]) #첫날
    
    for i in range(1,len(score)):
        if len(answer) >= k: 
            answer.append(score[i])
            answer.sort(reverse=True) 
            result.append(answer[k-1])
            continue
        
        answer.append(score[i])
        answer.sort()    
        result.append(answer[0])
    
    #answer.sort()
    
    return result