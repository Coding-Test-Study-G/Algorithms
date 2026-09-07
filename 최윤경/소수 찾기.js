/*
[접근]

1. 숫자 조각을 하나씩 선택해서 만들 수 있는 모든 숫자 생성 → 완전탐색
2. (현재까지 만든 숫자, 사용한 숫자) 상태로 DFS 재귀
3. 현재 숫자 소수 여부 검사
4. 중복 제외 → Set으로 저장 후 개수 반환
*/

function solution(numbers) {
  const digits = numbers.split("");
  const result = new Set();
  const visited = Array(digits.length).fill(false);

  function isPrime(num) {
    if (num < 2) return false;

    for (let i = 2; i * i <= num; i++) {
      if (num % i === 0) return false;
    }

    return true;
  }

  function dfs(current) {
    if (current.length > 0) {
      const num = Number(current);

      if (isPrime(num)) {
        result.add(num);
      }
    }

    for (let i = 0; i < digits.length; i++) {
      if (visited[i]) continue;

      visited[i] = true;

      dfs(current + digits[i]);

      visited[i] = false;
    }
  }

  dfs("");

  return result.size;
}
