def solution(s):
    answer = []
    dic = {}
    for i in range(len(s)):
        if s[i] in dic:
            idx = dic[s[i]]
        else : idx = s[:i].rfind(s[i])
        if idx != -1 : 
            answer.append(i - idx)
        else : answer.append(-1)
        dic[s[i]] = i
    return answer

"""
def solution(s):
    answer = []
    last_seen = dict()
    
    for i, char in enumerate(s):
        if char in last_seen:
            answer.append(i - last_seen[char])
        else:
            answer.append(-1)
        last_seen[char] = i  # 현재 문자의 위치를 최신으로 기록
    return answer
"""