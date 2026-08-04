"""
목표: 모든 음식의 스코빌 지수를 K 이상으로 만들기 위해 섞어야 하는 최소 횟수 찾기
- 섞은 스코빌 지수 = 스코빌 지수 최솟값 + 두 번째 최솟값 * 2

scoville: 음식들의 스코빌 지수
K: 원하는 스코빌 지수 
"""

from heapq import heapify, heappush, heappop

def solution(scoville, K):
    answer = 0
    heapify(scoville)
    while scoville:
        scov = heappop(scoville)
        if scov >= K:
            return answer
        if not scoville:
            return -1
        scov2 = heappop(scoville)
        new_scov = scov + scov2*2
        heappush(scoville, new_scov)
        answer += 1

    return answer