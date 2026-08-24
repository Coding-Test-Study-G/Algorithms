"""
최소의 비용으로 모든 섬이 서로 통행 가능하도록 만들 때 필요한 최소 비용?
- n개의 섬
- 다리 건설 비용 costs
-- costs 길이는 ((n-1) * n) / 2 이하
-- costs[i][0] 와 costs[i][1]에는 다리가 연결되는 두 섬의 번호가 들어있고
-- costs[i][2]에는 이 두 섬을 연결하는 다리를 건설할 때 드는 비용

<아이디어>
경로를 찾을 때 union find를 사용!
- 이유: union find는 tree 형태로 부모를 저장하며 parent를 자동 update하고, 
최소 개수의 경로를 빠르게 찾을 수 있음
costs를 sort하면 최소 비용의 최소 경로를 찾는데 용이함
"""

# 둘 사이를 연결하는 함수
def union(x, y):
    a = find(x)
    b = find(y)
    
    if a == b:
        return False
    else:
        parent[b] = a
        return True

# root 찾는 함수
def find(x):
    if parent[x] != x: # 자기 자신이 root인지 아닌지 판별
        return find(parent[x])
    return x # root를 찾으면 return

# union find 활용
def solution(n, costs):
    answer = 0
    
    costs.sort(key=lambda x: x[2])
    
    global parent
    parent = [i for i in range(n)]
    
    bridge_num = 0
    # union find로 연결될 때마다 cost update
    for x, y, cost in costs:
        if union(x, y):
            answer += cost
            bridge_num += 1
        # 모두 연결되면 break
        if bridge_num == n - 1:
            break
    
    return answer