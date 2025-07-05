def solution(food):
    answer = ''
    temp = []
    for i in range(1, len(food)):
        if food[i] == 1: continue 
        num =food[i]//2
        temp.extend(str(i)*num) 
    print(*temp)
    
    for j in range(len(temp)):
        answer += str(temp[j])
    answer += '0'
    for k in range(len(temp)-1,-1,-1):
        answer += str(temp[k])
    
    return answer