"""
n개의 노드(1 ~ n) 존재
목표: 1번에서 가장 멀리 떨어진 노드 개수 계산
- 가장 멀리 떨어진 노드: 최단 경로까지 간선 개수가 최대인 노드

Idea: graph를 만들어서 bfs로 각 노드마다 간선 개수 저장
"""

from collections import deque

def solution(n, vertex):
    answer = 0
    graph = [[] for _ in range(n+1)]
    for a, b in vertex:
        graph[a].append(b)
        graph[b].append(a)
    
    visited = [False for _ in range(n+1)]
    visited[1] = True
    
    count = [0 for _ in range(n+1)]
    
    queue = deque([(1, 0)])
    while queue:
        node, cnt = queue.popleft()
        for n in graph[node]:
            if not visited[n]:
                visited[n] = True
                queue.append([n, cnt+1])
                count[n] = cnt+1
    
    max_cnt = max(count)
    for cnt in count:
        if cnt == max_cnt:
            answer += 1
                        
    return answer