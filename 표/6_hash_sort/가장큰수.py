"""
0 또는 양의 정수가 주어졌을 때, 정수를 이어 붙여 만들 수 있는 가장 큰 수를 알아내 주세요.

- 모든 숫자를 같은 자릿수에서 비교
"""
def solution(numbers):
    answer = ''
    str_num = list(map(str, numbers))
    str_num.sort(key=lambda x: x*3, reverse=True)
    
    if all(s == '0' for s in str_num):
        return '0'
    
    return (answer.join(str_num))