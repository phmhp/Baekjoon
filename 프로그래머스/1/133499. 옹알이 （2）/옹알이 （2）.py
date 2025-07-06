def solution(babbling):
    answer = 0
    words = [ "aya", "ye", "woo", "ma" ]
    #visited = [False] * len(words)
    idx = 0 
    for bable in babbling:
        #print("----------------------")
        
        prev= ''
        while idx < len(bable):
            matched = False  # 이번 while 루프에서 단어가 매칭되었는지 여부
            for word in range(len(words)): 
            
                #print(words[word])
                if bable[idx:idx+len(words[word])] == words[word] and prev != word: 
                    
                    idx = idx+len(words[word])
                    matched = True
                    prev = word
                    break
            if not matched:
                break 
        if idx == len(bable):
            answer += 1 
            #print("answer+=1")

                    
        idx = 0
            

                            
    return answer