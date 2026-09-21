"""
'우선순위 큐 기반' 다익스트라 알고리즘
1. 주어진 그래프로 양방향 인접 리스트 구성
2. 최단 거리 테이블을 무한대로 초기화하고, 출발 노드(1번)의 거리를 0으로 설정 후 큐에 삽입
3. 큐에서 현재 최단 거리가 가장 짧은 노드를 꺼냄 (이미 처리된 거리보다 크면 스킵)
4. 해당 노드를 거쳐 인접 노드로 가는 거리를 계산하여, 기존 최단 거리보다 짧으면 갱신 후 큐에 삽입
5. 큐가 빌 때까지 3~4 과정을 반복
6. 1번 노드부터 N번 노드까지 중 최단 거리가 K 이하인 마을의 개수를 집계
"""

from heapq import heapify, heappush, heappop

def solution(N, road, K):
    answer = 0
    
    graph = [[] for _ in range(N+1)]
    for u, v, w in road:
        graph[u].append((w, v))
        graph[v].append((w, u))
    
    queue = []
    heappush(queue, (0, 1))
    distance = [1e8]*(N+1)
    distance[1] = 0
    
    while queue:
        # now: 현재 노드, dist: 이 노드까지의 거리
        dist, now = heappop(queue)
        # 현재 노드까지 거리가 더 크다면, 이미 처리된 노드
        if distance[now] < dist:
            continue
        # weight: now에서 node까지의 거리, node: now와 연결된 노드
        # distance[node]보다 dist + weight가 더 작다면, distance 업데이트 + 우선순위 큐에 추가
        for weight, node in graph[now]:
            new_dist = dist + weight
            # distance 모든 값이 inf여서 처음 한 번은 무조건 초기화가 되기 때문에 이 방법이 성립
            if new_dist < distance[node]:
                distance[node] = new_dist
                heappush(queue, (new_dist, node))
    
    for d in distance[1:]:
        if d <= K:
            answer += 1

    return answer