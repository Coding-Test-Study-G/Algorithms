"""
모든 차량이 고속도로를 이용하면서 단속용 카메라를 한 번은 만나도록 카메라를 설치
- 차량의 경로 routes
- routes[i][0]에는 i번째 차량이 고속도로에 진입한 지점
- routes[i][1]에는 i번째 차량이 고속도로에서 나간 지점

목표: 최소 몇 대의 카메라를 설치해야 하는지를 return

end만 파악하면 됨 (start 필요 x)
"""

def solution(routes):
    answer = 0
    
    routes.sort(key=lambda x: x[1])
    start, end = -30001, -30001
    for i, route in enumerate(routes):
        if end >= route[0]:
            continue
        elif end < route[0]:
            start, end = route[0], route[1]
            answer += 1
            if i == len(routes) - 1:
                i = 0
        if i == len(routes):
            answer += 1
    
    return answer