/*
[접근]

- 모든 경로를 탐색하면 중복 계산 발생 → DP
- 아래 두 숫자 중 큰 값을 선택 → 최대 경로
- 아래에서 위로 올라오며 각 위치의 최대값 갱신
*/

function solution(triangle) {
  for (let level = triangle.length - 2; level >= 0; level--) {
    for (let index = 0; index <= level; index++) {
      triangle[level][index] += Math.max(triangle[level + 1][index], triangle[level + 1][index + 1]);
    }
  }

  return triangle[0][0];
}
