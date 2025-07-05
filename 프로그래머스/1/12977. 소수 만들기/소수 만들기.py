def solution(nums):
    answer = 0
    path = []
    visited = [False] * len(nums)
    
    primes = [True] * 10001
    primes[0] = primes[1] = False
    for i in range(2, int(10000**0.5) + 1) : 
        if primes[i] :
            for j in range(i*i, 10001, i):
                primes[j] =False 
    #print(primes[:50])
     
    def recur(x):
        nonlocal answer 
        
        if len(path)==3 : 
            print(*path)
            if primes[sum(path)]:
                answer +=1
            return 
        
        for i in range(x,len(nums)):
            path.append(nums[i])
            recur(i+1)
            path.pop()
            
    recur(0)
    return answer