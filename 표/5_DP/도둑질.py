"""
각 집들은 서로 인접한 집들과 방범장치가 연결되어 있기 때문에 인접한 두 집을 털면 경보가 울립니다.
목표: 각 집에 있는 돈이 담긴 배열 money가 주어질 때, 도둑이 훔칠 수 있는 돈의 최댓값을 return
"""

def solution(money):
    length = len(money)
    
    # 마지막 집 안 터는 경우
    dp1 = [0]*length
    dp1[0] = money[0]
    dp1[1] = max(money[0], money[1])
    for i in range(2, len(money)-1):
        dp1[i] = max(dp1[i-1], dp1[i-2] + money[i])
    
    # 첫 집 안 터는 경우
    dp2 = [0]*length
    dp2[1] = money[1]
    dp2[2] = max(money[1], money[2])
    for i in range(3, len(money)):
        dp2[i] = max(dp2[i-1], dp2[i-2] + money[i])
    
    return max(dp1[length-2], dp2[length-1])