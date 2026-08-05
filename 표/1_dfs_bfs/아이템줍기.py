"""
겹쳐진 여러 개의 직사각형들을 하나의 다각형으로 인식하고, 가장 바깥쪽 테두리를 캐릭터의 이동 경로로 삼음
- 서로 다른 두 직사각형이 꼭짓점에서 만나거나, 변이 겹치는 경우 등은 없음
- 지형이 2개 이상으로 분리되는 경우도 없음
- 한 직사각형이 다른 직사각형의 내부에 있는 경우도 없음
- 다각형 내에 공백이 생길 수 있음
rectangle: 직사각형이 담긴 2차원 배열
- [좌측 하단 x, 좌측 하단 y, 우측 상단 x, 우측 상단 y]
characterX, characterY: 초기 캐릭터의 위치
itemX, itemY: 초기 아이템의 위치
Q. 캐릭터가 아이템을 줍기 위해 이동해야 하는 최단 거리는?

최단 거리이므로 bfs!
"""

from collections import deque

def solution(rectangle, characterX, characterY, itemX, itemY):
    """
    rectangle: 직사각형이 담긴 2차원 배열
    - [좌측 하단 x, 좌측 하단 y, 우측 상단 x, 우측 상단 y]
    characterX, characterY: 초기 캐릭터의 위치
    itemX, itemY: 초기 아이템의 위치
    
    <아이디어>
    여러 개의 사각형을 처리할 때, "테두리였다가 나중에 다른 사각형의 내부가 되는 곳"을 처리해야 함
    1. 테두리를 제외한 내부만 다시 0으로 파냄
    2. 내부가 된 적 없는 부분 중에 사각형의 테두리만 1로 채움
    3. 이 과정을 모든 사각형에 대해 반복하면, 어떤 사각형의 내부라도 된 적이 있는 곳은 무조건 0이 되어 테두리만 남음
    """
    
    itemX *= 2
    itemY *= 2
    field = [[-1]*102 for _ in range(102)]
    for rect in rectangle:
        points = list(map(lambda x: x*2, rect))
        x1,y1,x2,y2 = points[0],points[1],points[2],points[3]
        for x in range(x1, x2+1):
            for y in range(y1, y2+1):
                if x1 < x < x2 and y1 < y < y2:
                    field[y][x] = 0
                elif field[y][x] != 0:
                    field[y][x] = 1        
    
    visited = [[0]*102 for _ in range(102)]
    queue = deque([(characterX*2, characterY*2)]) # 현재 위치 g
    dx, dy = [1,-1,0,0], [0,0,1,-1]
    while queue:
        charX, charY = queue.popleft()
        if charX == itemX and charY == itemY:
            break
            
        for i in range(4):
            nx, ny = charX + dx[i], charY + dy[i]
            if not visited[ny][nx] and field[ny][nx] == 1:
                visited[ny][nx] = visited[charY][charX] + 1
                queue.append((nx, ny))
    
    return visited[itemY][itemX] // 2