/*
[접근]

- 모든 경로를 탐색 → DFS
- 현재 위치에서 아래 왼쪽 / 오른쪽으로 이동
- 모든 경로의 합을 비교 → 최댓값
- 같은 위치를 반복 방문 → 중복 계산 → 시간초과
*/
function solution(triangle) {
  var answer = 0;

  function max_path(level, index, sum) {
    if (level === triangle.length) {
      answer = Math.max(answer, sum);
      return;
    }

    sum += triangle[level][index];

    max_path(level + 1, index, sum);
    max_path(level + 1, index + 1, sum);
  }

  max_path(0, 0, 0);
  return answer;
}
