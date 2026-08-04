"""
"최소 필요 피로도"는 해당 던전을 탐험하기 위해 가지고 있어야 하는 최소한의 피로도
"소모 피로도"는 던전을 탐험한 후 소모되는 피로도
- 예시) "최소 필요 피로도"가 80, "소모 피로도"가 20인 던전을 탐험하기 위해서는 유저의 현재 남은 피로도(k)는 80 이상 이어야 하며, 
        던전을 탐험한 후에는 피로도 20이 소모
하루에 한 번씩 탐험할 수 있는 던전이 여러개 존재

dungeons: 각 던전별 "최소 필요 피로도", "소모 피로도"가 담긴 2차원 배열
***dungeons의 세로(행) 길이(즉, 던전의 개수): 1 이상 8 이하 *** -> 완탐 가능
k: 유저의 현재 피로도
***k: 1 이상 5,000 이하 ***

목표: 유저가 탐험할수 있는 최대 던전 수를 return
"""

from itertools import permutations

def solution(k, dungeons):
    answer = -1
    ways = list(permutations(dungeons, len(dungeons)))
    for way in ways:
        cur_k = k
        num = 0
        for min_k, used_k in way:
            if cur_k >= min_k:
                cur_k -= used_k
                num += 1
            else:
                break
        answer = max(answer, num)
        
    return answer