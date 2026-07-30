"""
<요약>
100% -> 서비스 반영
뒤에 있는 기능은 앞에 있는 기능이 100%가 돼야만 배포 가능
progresses: 각 기능의 배포 순서대로 현재 진도를 담음
speeds: 각 기능별 개발 속도

Q. 배포 시점마다 몇 개 기능 배포?  
"""
from collections import deque
def solution(progresses, speeds):
    answer = []
    queue = deque([(p,s) for p,s in zip(progresses, speeds)])
    while queue:
        num = 1
        p, s = queue.popleft()
        time = (100 - p) // s
        if (100 - p) % s > 0:
            time += 1
        while queue:
            q_p, q_s = queue[0]
            q_p += q_s * time
            if q_p >= 100:
                queue.popleft()
                num += 1
            else:
                break
        answer.append(num)
        
    return answer