"""
<문제 요약>
흩어진 종이 조각을 붙여 소수를 몇 개 만들 수 있는지 알아내려 합니다.
각 종이 조각에 적힌 숫자가 적힌 문자열 numbers가 주어졌을 때, 종이 조각으로 만들 수 있는 소수가 몇 개인지 return
***numbers는 길이 1 이상 7 이하 *** -> 완탐 가능

<아이디어>
1. 주어진 numbers로 조합 가능한 모든 숫자를 만든다
2. 각 숫자마다 sqrt 적용한 후 이 결과값까지 나누면서 나머지 0인지 확인
"""

from itertools import permutations
from math import sqrt
def solution(numbers):
    answer_set = set()
    nums = [n for n in numbers]
    length = len(numbers)
    
    # 순열 길이 (2 ~ length+1)
    for l in range(1, length+1):
        candidates_str = set(permutations(nums, l))
        
        # 각 순열 -> int로 변경 -> 소수 판별
        for cand_str in candidates_str:
            
            # 예외 처리
            if cand_str == ("1",) or cand_str[0] == "0":
                continue
            
            # 후보 숫자 생성
            cand = ""
            for s in cand_str:
                cand += s
            cand = int(cand)
            
            # 소수 판별
            sqrt_num = int(sqrt(cand))
            is_prime = True
            
            for n in range(2, sqrt_num+1):
                if cand % n == 0:
                    is_prime = False
                    break
            
            # 소수면 추가
            if is_prime:
                print(cand)
                answer_set.add(cand)
    
    return len(answer_set)