from collections import Counter

def solution(X, Y):  
      
    answer = []
    
    counterX = Counter(X)
    counterY = Counter(Y)  
    print(counterX) #	Counter({'1': 2, '2': 2, '3': 1})
    
    for x in X : 
        if counterY.get(x,0) >= 1: 
            counterY[x] -=1 
            counterX[x] -=1
            answer.append(x)
    answer.sort(reverse=True)    
    if len(answer) == 0 :
        return "-1"
    elif answer[0] == "0" :
        return "0"
    else : 
        return ''.join(answer)