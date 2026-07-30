"""
<규칙>
1. 실행 대기 큐(Queue)에서 대기중인 프로세스 하나를 꺼냅니다.
2. 큐에 대기중인 프로세스 중 우선순위가 더 높은 프로세스가 있다면 방금 꺼낸 프로세스를 다시 큐에 넣습니다.
3. 만약 그런 프로세스가 없다면 방금 꺼낸 프로세스를 실행합니다.
  3.1 한 번 실행한 프로세스는 다시 큐에 넣지 않고 그대로 종료됩니다.
<목표>
 특정 프로세스가 몇 번째로 실행되는지 알아내는 것

"""
from collections import deque

def solution(priorities, location):
    answer = 0
    queue = deque([(i, p) for i, p in enumerate(priorities)])
    while queue:
        i, q = queue.popleft() # 0, 1
        
        if any([que > q for j, que in queue]):
            queue.append((i, q))
        else:
            answer += 1
            if i == location:
                break
            
    return answer