/*
[접근]

1. 보조 벨트는 마지막에 넣은 상자부터 꺼내므로 스택(LIFO)으로 구현
2. 목표 상자 전까지의 상자는 stack에 push
3. 현재 상자 또는 stack의 top이 목표 상자면 적재
4. 둘 다 불가능하면 종료 후 적재한 개수 반환
*/

function solution(order) {
  const stack = [];
  let box = 1;
  let count = 0;

  for (const target of order) {
    while (box < target) {
      stack.push(box);
      box++;
    }

    if (box === target) {
      box++;
      count++;
    } else if (stack.length && stack[stack.length - 1] === target) {
      stack.pop();
      count++;
    } else {
      break;
    }
  }

  return count;
}
