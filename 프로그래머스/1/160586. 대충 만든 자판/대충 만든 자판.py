def solution(keymap, targets): #targets = 입력하려는 문자열 / keymap = 할당된 키값 
    answer = []
    total = 0
    #total += min (keymap) 값 
    #answer.append(total)
    
    for target in targets: #요소 1개 
        
        total = 0
        for i in target : #i = 한글자 
            mi = float('inf')
            for n in range(len(keymap)):
                curr = keymap[n].find(i)
                if mi > curr+1 and curr != -1: mi = curr+1
            
            if mi == float('inf'):  
                total = -1 
                break
            else : total += mi
        answer.append(total)
        
    return answer