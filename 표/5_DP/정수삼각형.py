"""
위와 같은 삼각형의 꼭대기에서 바닥까지 이어지는 경로 중, 거쳐간 숫자의 합이 가장 큰 경우 찾기
- 아래 칸으로 이동할 때는 대각선 방향으로 한 칸 오른쪽 또는 왼쪽으로만 이동 가능

*** 삼각형의 높이는 1 이상 500 이하
*** 삼각형을 이루고 있는 숫자는 0 이상 9,999 이하의 정수

각 지점마다 가질 수 있는 최댓값을 업데이트하면서 내려가면, 마지막 줄에서 답들이 모임
이들 중 최댓값만 찾으면 됨!
-> DP
"""

def solution(triangle):
    n = len(triangle)
    
    for i in range(1, n):
        length = len(triangle[i])
        for j in range(length):
            if j == 0:
                triangle[i][j] += triangle[i-1][j]
            elif j == len(triangle[i-1]):
                triangle[i][j] += triangle[i-1][j-1]
            else:
                triangle[i][j] += max(triangle[i-1][j-1], triangle[i-1][j])
    
    return max(triangle[n-1])