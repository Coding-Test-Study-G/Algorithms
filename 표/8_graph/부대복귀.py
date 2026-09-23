"""
목표: sources의 원소 순서대로 강철부대로 복귀할 수 있는 최단시간을 담은 배열을 return
- 두 지역 간의 길을 통과하는 데 걸리는 시간은 모두 1로 동일
- 강철부대가 위치한 지역을 포함한 총지역의 수 n
- 두 지역을 왕복할 수 있는 길 정보를 담은 2차원 정수 배열 roads
- 각 부대원이 위치한 서로 다른 지역들을 나타내는 정수 배열 sources
- 강철부대의 지역 destination
- 복귀가 불가능한 경우 해당 부대원의 최단시간은 -1
"""

from collections import deque
def solution(n, roads, sources, destination):    
    graph = [[] for _ in range(n+1)]
    for a, b in roads:
        graph[a].append(b)
        graph[b].append(a)
    
    distances = [-1]*(n+1)
    distances[destination] = 0
        
    visited = [False]*(n+1)
    visited[destination] = True

    q = deque([destination])
    while q:
        s = q.popleft()
        for node in graph[s]:
            if not visited[node]:
                q.append(node)
                visited[node] = True
                distances[node] = distances[s] + 1
    
    answer = [distances[source] for source in sources]
    
    return answer