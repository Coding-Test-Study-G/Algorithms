def solution(targets):
    answer = 0
    
    if len(targets) == 1:
        return 1
    
    targets.sort(key=lambda x: (x[1], -x[0]))
    
    start = targets[0][0]
    end = targets[0][1]
    
    i = 1
    while True:
        s, e = targets[i]
        if end <= s:
            answer += 1
            end = e
        
        if i == len(targets) - 1:
            if end > s:
                answer += 1
            break
            
        i += 1
    
    return answer