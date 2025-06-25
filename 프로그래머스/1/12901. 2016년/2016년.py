def solution(a, b):
    
    month = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    
    day = sum(month[:a-1]) 
    day += b 
    
    #      0     1     2     3     4     5     6
    d = ["THU","FRI","SAT","SUN","MON","TUE","WED"]
    if day < 7 :
        return d[day]
    
    return d[day % 7]
