"""
단어 조각이 [“ba”, “na”, “n”, “a”]인 경우 "ba", "na", "n", "a" 단어 조각이 각각 무한개씩 있습니다. 
사용 가능한 단어 조각들을 담고 있는 배열 strs와 완성해야 하는 문자열 t가 매개변수로 주어질 때,
목표: 주어진 문장을 완성하기 위해 사용해야 하는 단어조각 개수의 최솟값을 return
- 완성하는 것이 불가능하면 -1을 return 
"""

def solution(strs, t):
    strs = set(strs)
    length = len(t)
    
    dp = [20001] * (length+1)
    dp[0] = 0
    
    # t[i-l:i] 구간의 조각이 strs에 있고, 이전 구간(dp[i-l])에 도달 가능했다면
    # t[i]까지 향하는 모든 경우의 수를 구할 수 있음
    for i in range(1, length + 1):   # i: 1 ~ length
        for j in range(1, 6):   # j: 1 ~ 5
            if i >= j:
                # t[i-j:i] 구간의 조각이 strs에 있고, 이전 구간(dp[i-j])에 도달했다면
                # 이전의 모든 구간에서 올 수 있는 경우의 수를 구할 수 있음
                if t[i-j:i] in strs and dp[i-j] != 20001:
                    dp[i] = min(dp[i], dp[i-j] + 1)
    
    if dp[length] == 20001:
        return -1
    
    return dp[length]