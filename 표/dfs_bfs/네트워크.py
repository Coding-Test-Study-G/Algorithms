"""
n: 컴퓨터 개수 (1 <= n <= 200)
computers: 연결 정보를 담은 2차원 배열 (0 ~ n-1로 표현, 연결: 1)
- [[1, 1, 0], [1, 1, 0], [0, 0, 1]]에서 
  1,1,0은 각각 1,2,3번째 컴퓨터에 연결,연결,비연결 상태임을 의미
- computers[i][i]는 항상 1 -> 즉 자기 자신과는 항상 연결
- 아무것도 연결되지 않은 컴퓨터도 하나의 네트워크로 간주
Q. 네트워크의 개수는? 
"""

def solution(n, computers):
    answer = 0
    visited = [False]*n
    
    def dfs(i):
        nonlocal visited
        for j, connected in enumerate(computers[i]):
            if connected and not visited[j]:
                visited[j] = True
                dfs(j)
        
    for k in range(n):
        if not visited[k]:
            dfs(k)
            answer += 1
    
    return answer