"""
0 또는 양의 정수가 주어졌을 때, 정수를 이어 붙여 만들 수 있는 가장 큰 수를 알아내 주세요.

- 모든 숫자를 같은 자릿수에서 비교
"""
def solution(numbers):
    answer = ''
    nums = [str(n) for n in numbers]
    nums.sort(key=lambda x: x*3, reverse=True)
    if all(n==0 for n in numbers):
        return '0'
    for num in nums:
        answer += num
    return answer