/*
[접근]

1. 조이스틱 조작 횟수의 최솟값
2. 알파벳 위/아래 중 더 짧은 방향을 바로 선택 가능 -> 그리디
3. 커서도 A 구간을 피해서 가장 짧은 이동 방법을 선택
4. 오른쪽 / 오른쪽 -> 왼쪽 / 왼쪽 -> 오른쪽 중 최소 이동 계산
*/

function solution(name) {
  let answer = 0;

  // 커서 이동 횟수 : 커서 오른쪽으로만
  let move = name.length - 1;

  for (let i = 0; i < name.length; i++) {
    // 알파벳 변경 최소값
    const diff = name.charCodeAt(i) - 'A'.charCodeAt(0);
    answer += Math.min(diff, 26 - diff); // 다음, 이전 최소 값

    // 연속 A 찾기
    let next = i + 1;
    while (next < name.length && name[next] === 'A') next++;

    // 커서 이동 최소 횟수
    move = Math.min(
      move, // 오른쪽으로만
      i * 2 + name.length - next, // 오른쪽 -> 왼쪽
      (name.length - next) * 2 + i, // 왼쪽 -> 오른쪽
    );
  }

  return answer + move;
}
