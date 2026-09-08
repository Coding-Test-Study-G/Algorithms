"""
n명의 권투선수가 권투 대회에 참여, 권투 경기는 1대1 방식
만약 A 선수가 B 선수보다 실력이 좋다면 A 선수는 B 선수를 항상 이깁니다.
몇몇 경기 결과를 분실하여 정확하게 순위를 매길 수 없습니다.
- 선수의 수: n
- 경기 결과를 담은 2차원 배열: results
- [A, B]는 A 선수가 B 선수를 이겼다는 의미
목표: 정확하게 순위를 매길 수 있는 선수의 수를 return

! A가 B에게 이기고 B가 C에게 이기면, A가 C에게 이김
"""

def solution(n, results):
    answer = 0
    
    graph = [[set(), set()] for _ in range(n+1)]
    for win, lose in results:
        graph[win][0].add(lose)
        graph[lose][1].add(win)
        
    for i in range(1, n+1):
        win_list, lose_list = graph[i]
        for w in win_list: # i한테 진 애들은 i를 이긴 애들한테 짐
            graph[w][1].update(graph[i][1])
        for l in lose_list: # i한테 이긴 애들은 i한테 진 애들한테 이김
            graph[l][0].update(graph[i][0])
    
    for i in range(1, n+1):
        if len(graph[i][0]) + len(graph[i][1]) == n-1:
            answer += 1

    return answer