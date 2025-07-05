def solution(s):
    answer = 0
    i = 0
    
    while i<len(s):
        # if i == len(s)-1 :
        #     answer += 1 
        #     break
        x = s[i] 
        xcnt,ocnt = 0,0
        for j in range(i, len(s)):
            if s[j]==x: xcnt += 1
            else : ocnt +=1
            
            if xcnt==ocnt :
                answer += 1 
                i = j+1
                break
        else : 
            answer += 1 
            break
    return answer