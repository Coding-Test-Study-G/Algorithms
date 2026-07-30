"""
<문제 요약>
캐릭터가 움직일 때는 동, 서, 남, 북 방향으로 한 칸씩 이동하며, 게임 맵을 벗어난 길은 갈 수 없음.
게임 맵의 상태 maps가 매개변수로 주어질 때, 
캐릭터가 상대 팀 진영에 도착하기 위해서 지나가야 하는 칸의 개수의 최솟값을 return.
단, 상대 팀 진영에 도착할 수 없을 때는 -1을 return.
** 0은 벽이 있는 자리, 1은 벽이 없는 자리 **

최단 거리를 찾아야 하니, bfs를 사용하자!
"""

from collections import deque

def solution(maps):
    n, m = len(maps), len(maps[0]) # 세로, 가로
    queue = deque([(1, 0, 0)])
    dx, dy = [1, -1, 0, 0], [0, 0, 1, -1]
    visited = [[False]*(m) for _ in range(n)]
    while queue:
        ans, x, y = queue.popleft()
        
        if x == m-1 and y == n-1:
            return ans
        
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < m and 0 <= ny < n and not visited[ny][nx] and maps[ny][nx] == 1:
                visited[ny][nx] = True
                queue.append((ans+1, nx, ny))
                
    return -1 