"""
n개의 송전탑이 전선을 통해 하나의 트리 형태로 연결
이 전선들 중 하나를 끊어서 현재의 전력망 네트워크를 2개로 분할
송전탑 개수가 가능한 비슷하도록 두 전력망으로 나누었을 때, 두 전력망이 가지고 있는 송전탑 개수의 차이(절대값)를 return
- 송전탑의 개수: n (2 <= n <= 100)
- 전선 정보: wires (n-1개)
  - 자기 연결은 없음

"""

def solution(n, wires):
    answer = 100
    
    def dfs(node): 
        nonlocal visited
        
        if visited[node]:
            return
        
        visited[node] = 1
        for j, (w1, w2) in enumerate(wires):
            if i == j:
                continue
            if node == w1:
                dfs(w2)
            elif node == w2:
                dfs(w1)
    
    for i in range(n-1): 
        visited = [0]*(n+1)
        
        dfs(1)
        
        num1 = visited.count(1)
        num2 = n - num1
        answer = min(answer, abs(num1 - num2))
        
            
    return answer