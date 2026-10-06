"""
목표: 바위 n개를 제거했을 때, 바위 사이 거리의 최솟값이 가장 큰 경우의 값을 구하는 것

distance: 목표지점까지의 거리
rocks: 바위의 위치
n: 제거할 바위 개수
- 바위를 전부 제거하는 경우도 존재함

아이디어: 거꾸로 생각해보자. 최솟값 중 가장 크다는 것은, 임의로 정한 최솟값보다 작은 거리의 수가 n이라는 의미. 그러니 n이 될 때까지 반복 확인해보면 된다!
"""

def solution(distance, rocks, n):
    answer = 0
    
    if n == len(rocks):
        return distance
    
    rocks.sort()
    rocks.append(distance)
    
    start = 0
    end = distance
    dists = []
    
    while start <= end:
        mid = (start + end) // 2
        exp = 0
        cur = 0
        for r in rocks:
            if r - cur < mid:
                exp += 1
            else:
                cur = r
        
        if exp <= n:   # 더 적은 경우: mid를 키워야 함
            answer = mid
            start = mid + 1
        else:          # 더 많은 경우: mid를 줄여야 함
            end = mid - 1
        
    return answer