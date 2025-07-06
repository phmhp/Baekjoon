def solution(k, m, score):
    answer = 0
    #사과의 최대 점수 k, 한 상자에 들어가는 사과의 수 m, 사과들의 점수 score
    #m을 만족하는 선에서 가장 최하위 점수들은 버리기 -> 최대 이익이 얼마인지? 
    
    score.sort(reverse=True) #내림차순 정렬 
    #print(score)
    k = 0 
    for i in range(len(score) // m):
        
        if k+m <= len(score):
            answer += min(score[k:k+m])*m
            #print(min(score[k:k+m])*m)
            #print(score[k:k+m])
            k = k+m
            
    return answer