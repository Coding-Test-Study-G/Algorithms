"""
목표: 모든 사람이 심사를 받는데 걸리는 시간의 최솟값 찾기

1. n: 심사 받는 사람의 수
2. times: 각 심사관이 심사하는데 걸리는 시간
"""

def solution(n, times):
    answer = 0
    
    times.sort()
    start = 0
    end = min(times)*n
    
    while start <= end:
        mid = (start + end) // 2
        exp = 0
        
        for t in times:
            exp += mid // t
            
        if exp >= n:
            answer = mid
            end = mid - 1
        else:
            start = mid + 1
    
    return answer 