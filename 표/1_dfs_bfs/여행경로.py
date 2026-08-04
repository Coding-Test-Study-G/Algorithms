"""
모든 티켓을 사용했을 때, 방문하는 공항 경로 배열은?
- 항상 ICN 에서 출발
- 모든 공항은 알파벳 대문자 3글자
- 공항 수는 3 이상 10000 이하
- 가능한 경로가 2개 이상일 경우 알파벳 순서가 앞서는 경로를 return
- 모든 도시를 방문 가능한 경우의 수가 항상 존재

모든 경로를 찾아야 하므로 dfs!
"""


def solution(tickets):
    answers = []
    
    def dfs(stack, visited):
        nonlocal answers
        
        # stop 조건
        if len(stack) == len(tickets) + 1: 
            answers.append(stack[:])
            return
        
        # 각 지점마다 현재 경로와 visited를 재귀로 부름
        ### dfs 호출 이후 원상복구를 시켜야 여러 개의 분기가 생길 때 모든 경로 탐색 가능
        for j, (dep, arr) in enumerate(tickets): 
            if dep == stack[-1] and not visited[j]:
                visited[j] = True
                stack += [arr]
                
                dfs(stack, visited)
                
                stack.pop()
                visited[j] = False
    
    # 출발점과 visited를 함께 인풋으로 하는 dfs 호출
    for i, (dep, arr) in enumerate(tickets):
        if dep == "ICN":
            visited = [False]*len(tickets)
            visited[i] = True
            stack = [dep, arr]
            dfs(stack, visited)
        
        
    return sorted(answers)[0]