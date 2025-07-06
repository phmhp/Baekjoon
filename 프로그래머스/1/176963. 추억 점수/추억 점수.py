def solution(name, yearning, photo):
    answer = []
    dic = {n:y for n,y in zip(name,yearning)}
    #print(dic)
    for pho in photo:
        temp = 0
        for name in pho:
            if name in dic:
                temp += dic[name]
        answer.append(temp)
    return answer