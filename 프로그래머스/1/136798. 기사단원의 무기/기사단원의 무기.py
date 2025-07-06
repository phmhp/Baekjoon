def solution(number, limit, power):
    answer = 0
    num = []

    for i in range(1,number+1):
        count = 0
        for j in range(1, int(i**0.5)+1):
            if i % j == 0 : 
                count += 1
                if j != i//j : 
                    count += 1 

        num.append(count)
        
    for k in num :
        if k <= limit:
            answer += k 
        else : answer += power
    
    return answer
    