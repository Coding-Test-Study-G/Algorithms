"""
조이스틱으로 알파벳 이름을 완성하세요. 맨 처음엔 A로만 이루어져 있습니다.
- ex) 완성해야 하는 이름이 세 글자면 AAA, 네 글자면 AAAA

▲ - 다음 알파벳
▼ - 이전 알파벳 (A에서 아래쪽으로 이동하면 Z로)
◀ - 커서를 왼쪽으로 이동 (첫 번째 위치에서 왼쪽으로 이동하면 마지막 문자에 커서)
▶ - 커서를 오른쪽으로 이동 (마지막 위치에서 오른쪽으로 이동하면 첫 번째 문자에 커서)
"""

def solution(name):
    answer = 0
    
    min_move = len(name)
    for i, n in enumerate(name):
        # 세로 방향 조작
        if n == 'A':
            pass
        else:
            answer += min(ord('Z') - ord(n) + 1, ord(n) - ord('A'))
        
        # 가로 방향 조작
        move = i + 1
        while move < len(name) and name[move] == 'A':
            move += 1
        
        # 유턴 고려 - ???
        min_move = min(
            min_move,
            i*2 + len(name) - move,
            (len(name) - move)*2 + i
        )

    answer += min_move
        
    return answer