/*
[접근]

- 앞자리가 큰 숫자를 만들어야 함 → 그리디
- 현재 숫자와 가장 최근에 선택한 숫자부터 비교 → Stack
- 순회 종료 후 k 남을 경우 뒤에서 제거
*/

function solution(number, k) {
  var answer = '';

  const stack = [];

  for (let i = 0; i < number.length; i++) {
    const current = number[i];

    while (k > 0 && stack.length > 0 && stack[stack.length - 1] < current) {
      stack.pop();
      k--;
    }
    stack.push(current);
  }

  if (k > 0) {
    stack.splice(stack.length - k, k);
  }

  return stack.join('');
}
