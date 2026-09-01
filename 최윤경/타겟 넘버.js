/*
[접근]

1. 숫자마다 +, - 두 가지 경우 → 완전탐색
2. (현재 인덱스, 누적합)을 상태로 DFS 재귀
3. 탐색 끝 => target과 비교 → 일치하면 경우의 수 +1
*/

function solution(numbers, target) {
  var answer = 0;

  function dfs(index, sum) {
    if (index === numbers.length) {
      if (sum === target) {
        answer++;
      }
      return;
    }

    dfs(index + 1, sum + numbers[index]);
    dfs(index + 1, sum - numbers[index]);
  }

  dfs(0, 0);

  return answer;
}
