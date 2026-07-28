from collections import deque

def solution(prices):
    answer = []
    queue = deque(prices)
    while queue:
        price = queue.popleft()
        time = 0
        for p in queue:
            if p < price:
                time += 1
                break
            time += 1
        answer.append(time)
    
    return answer