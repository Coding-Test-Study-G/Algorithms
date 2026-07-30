"""개수를 찾을 때는 dfs"""

def solution(numbers, target):
    answer = 0
    length = len(numbers)
    
    def dfs(i, num):
        nonlocal answer
        if i == length:
            if num == target:
                answer += 1
            return
                
        dfs(i+1, num+numbers[i])
        dfs(i+1, num-numbers[i])
    
    dfs(0,0)
    
    return answer