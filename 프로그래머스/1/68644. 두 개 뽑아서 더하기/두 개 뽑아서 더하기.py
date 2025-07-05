def solution(numbers):
    answer = []
    path = []
    #조합 
    #set_num = list(set(numbers))
    
    def recur (start):
        if len(path) == 2: 
            print(*path)
            answer.append(sum(path))
            return 
        
        for i in range(start, len(numbers)):
            path.append(numbers[i])
            recur(i+1)
            path.pop()
    recur(0)
    answer = list(set(answer))
    answer.sort()
    return answer