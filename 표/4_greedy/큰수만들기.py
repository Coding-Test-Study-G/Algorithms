"""
어떤 숫자에서 k개의 수를 제거했을 때 얻을 수 있는 가장 큰 숫자를 구하려 합니다.
예시) 숫자 1924에서 수 두 개를 제거하면 [19, 12, 14, 92, 94, 24] 를 만들 수 있습니다. 이 중 가장 큰 숫자는 94 입니다.
- 문자열 형식으로 숫자 number
- 제거할 수의 개수 k
number에서 k 개의 수를 제거했을 때 만들 수 있는 수 중 가장 큰 숫자를 문자열 형태로 return

*** number는 2자리 이상, 1,000,000자리 이하인 숫자입니다.
k는 1 이상 number의 자릿수 미만인 자연수입니다. ***

# 1. 모든 숫자를 순서대로 순회
# 2. answer에 값이 있고, k > 0 (아직 지울 횟수가 남음), 숫자가 마지막 자리 수보다 크면 마지막 자리 수를 삭제
"""

def solution(number, k):
    answer = []
    for num in number:
        while answer and k > 0 and num > answer[-1]:
            answer.pop()
            k -= 1
        answer.append(num)

    # k가 남아있으면 뒤로 갈수록 값이 우하향하는 경우 -> 뒤에서부터 제거
    while k > 0:
        answer.pop()
        k -= 1
    
    return "".join(answer)