/*
[접근]

1. 선수 간 승패는 A가 B를 이겼다는 방향이 있는 관계 → 방향 그래프로 표현
2. 직접 경기 결과만으로는 순위를 알 수 없으므로 연결된 승패 관계까지 확인 필요
   → A가 B를 이기고 B가 C를 이기면 A가 C를 이김
3. 모든 선수 사이의 간접 승패 관계를 확인해야 함 → 플로이드-워셜
4. 한 선수가 자신을 제외한 모든 선수와 승패 관계가 정해지면 정확한 순위 확정
5. 승패 관계를 알 수 있는 선수가 n-1명인 선수의 수 반환
*/

function solution(n, results) {
  let answer = 0;
  const win = Array.from({ length: n + 1 }, () => Array(n + 1).fill(false));

  // 승패 저장
  for (const [winner, loser] of results) {
    win[winner][loser] = true;
    win[loser][winner] = false;
  }

  // 연관 승패 저장
  for (let k = 1; k <= n; k++) {
    for (let i = 1; i <= n; i++) {
      for (let j = 1; j <= n; j++) {
        if (win[i][k] && win[k][j]) {
          win[i][j] = true;
        }
      }
    }
  }

  // 선수별 순위 확정 가능 여부 확인
  for (let i = 1; i <= n; i++) {
    let known = 0;

    for (let j = 1; j <= n; j++) {
      if (i === j) continue;

      if (win[i][j] || win[j][i]) {
        known++;
      }
    }

    // 모든 관계 안다면 정답++
    if (known === n - 1) {
      answer++;
    }
  }

  return answer;
}
