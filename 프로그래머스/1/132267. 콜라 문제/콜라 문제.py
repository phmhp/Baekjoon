def solution(a, b, n):
    answer = 0
    
    while (n >= a):
        pack = n//a
        new_get=pack*b
        
        answer += new_get #다시 받을 수 있는 병의 수  
        #print(answer)
        n = n - a*(pack)+(new_get) #가지고 있던 병의 수 - 가져다준 병의 수 + 새로 받은 병의 수 
        #print("n:",n)
        continue 
    return answer

