"""
가장 왼쪽 위, 즉 집이 있는 곳의 좌표는 (1, 1)로 나타냄 
가장 오른쪽 아래, 즉 학교가 있는 곳의 좌표는 (m, n)
- 집에서 학교까지 가는 길은 m x n 크기의 격자모양
- 격자의 크기 m, n과 물이 잠긴 지역의 좌표를 담은 2차원 배열 puddles

목표: 오른쪽과 아래쪽으로만 움직여 집에서 학교까지 갈 수 있는 최단경로의 개수를 1,000,000,007로 나눈 나머지를 return

DP로 칸마다 윗칸과 왼쪽 칸의 값을 더하자!
"""

def solution(m, n, puddles):  
    tiles = [[0 for _ in range(m+1)] for _ in range(n+1)]
    tiles[1][1] = 1
    for puddle in puddles:   # 물이 잠긴 지역은 -1 처리
        tiles[puddle[1]][puddle[0]] = -1
    dx, dy = [1, 0], [0, 1]
    
    for y in range(1, n+1):
        for x in range(1, m+1):
            if tiles[y][x] >= 0:
                if tiles[y][x-1] >= 0:
                    tiles[y][x] += tiles[y][x-1]
                if tiles[y-1][x] >= 0:
                    tiles[y][x] += tiles[y-1][x]
                
    return tiles[n][m] % 1000000007