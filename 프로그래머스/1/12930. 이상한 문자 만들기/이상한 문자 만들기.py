def solution(s):
    answer = ''
    idx = 0 
    
    for i in range(len(s)) : 
        if s[i] == ' ': idx = i+1
        if (i-idx)%2 == 0:
            answer+=(s[i].upper())
        else : 
            answer+=(s[i].lower())
    print(answer)
    return answer