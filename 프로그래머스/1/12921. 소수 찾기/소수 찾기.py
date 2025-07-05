def solution(n):
    answer = 0
    primes = [True] * (n+1) #n+1개의 True리스트 생성
    primes[0] = primes[1] = False # 0과 1은 소수가 아님 
    
    for i in range(2,int(n**0.5)+1) : #2부터 root n 까지 
        if primes[i] : #소수라면 
            for j in range(i*i, n+1, i) : #i의 배수들을 모두 False로 지움 
                primes[j] = False 
    return sum(primes) #True(소수)인 개수만 합산 