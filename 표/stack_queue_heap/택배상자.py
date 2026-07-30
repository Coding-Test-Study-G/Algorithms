"""
<문제 설명>
1 ~ n번 상자까지 오름차순으로 전달
전달된 순서대로 확인 시작
order에 맞지 않는 상자는 stack에 넣음
stack에 넣은 후에 order에 맞게 실지 못하면 종료

"""

def solution(order):
    answer = 0
    stack = [] # 보조 벨트
    
    box = 1
    for target in order:
        # box가 order보다 커지면 안됨 & box가 target보다 커도 안 됨
        while box <= len(order) and box < target:
            stack.append(box)
            box += 1
        
        # 보조 벨트에서 답 있으면
        if box == target:
            answer += 1
            box += 1
        elif stack[-1] == target:
            answer += 1
            stack.pop()
        # 답 없으면    
        else: 
            return answer
            
    return answer