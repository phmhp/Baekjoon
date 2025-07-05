def solution(sizes):
    answer = 0
    x_list = []
    y_list = []
    for x,y in sizes:
        x, y = max(x,y), min(x,y)
        x_list.append(x)
        y_list.append(y)
    return max(x_list) * max(y_list)
    