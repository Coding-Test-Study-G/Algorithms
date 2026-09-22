"""
- 지점의 개수 n
- 출발지점을 나타내는 s
- A의 도착지점을 나타내는 a
- B의 도착지점을 나타내는 b
- 지점 사이의 예상 택시요금을 나타내는 fares
목표: A, B 두 사람이 s에서 출발해서 각각의 도착 지점까지 택시를 타고 간다고 가정할 때, 
     최저 예상 택시요금을 계산해서 return
     => 다익스트라 알고리즘 3번 or 플로이드-워셜 알고리즘
"""

# 다익스트라 알고리즘
from heapq import heappush, heappop
def solution(n, s, a, b, fares):
    answer = 1e10
    
    graph = [[] for _ in range(n+1)]
    for c, d, f in fares:
        graph[c].append((d, f))
        graph[d].append((c, f))
    
    def dijkstra(start):
        costs = [1e8]*(n+1)
        costs[start] = 0

        q = []
        heappush(q, (0, start))
         
        while q:
            fare, now = heappop(q)

            if costs[now] < fare:
                continue

            for node, f in graph[now]:
                new_fare = fare + f
                if new_fare < costs[node]:
                    costs[node] = new_fare
                    heappush(q, (new_fare, node))
        
        return costs
    
    s_cost = dijkstra(s)
    a_cost = dijkstra(a)
    b_cost = dijkstra(b)
    
    for i in range(1, n+1):
        cost = s_cost[i] + a_cost[i] + b_cost[i]
        answer = min(cost, answer)
    
    return answer


# 플로이드-워셜 알고리즘
def solution(n, s, a, b, fares):
    answer = 1e10
    
    dist = [[1e10]*(n+1) for _ in range(n+1)]
    
    for i in range(1, n+1):
        dist[i][i] = 0
        
    for c, d, f in fares:
        dist[c][d] = f
        dist[d][c] = f
    
    for k in range(1, n+1): # 경유지
        for i in range(1, n+1): # 출발
            for j in range(1, n+1): # 도착
                if dist[i][k] + dist[k][j] < dist[i][j]:
                    dist[i][j] = dist[i][k] + dist[k][j]
    
    for l in range(1, n+1): # l: 경유지
        value = dist[s][l] + dist[l][a] + dist[l][b]
        answer = min(value, answer)
    
    return answer